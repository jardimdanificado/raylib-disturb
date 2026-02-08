#!/usr/bin/env python3
import json
import pathlib
import re
from collections import Counter, defaultdict

ROOT = pathlib.Path(__file__).resolve().parent.parent
TOOLS = ROOT / "tools"
GEN = ROOT / "generated"
GEN.mkdir(exist_ok=True)

INV_PATH = TOOLS / "raylib_inventory.json"
PLAN_PATH = GEN / "plan.json"
CONST_PATH = GEN / "raylib_constants.dist"
REPORT_PATH = GEN / "report_phase2.md"
SHIM_H_PATH = GEN / "raylib_shim_phase2.h"
FFI_PATH = GEN / "raylib_ffi_phase2.dist"
NEEDS_MANUAL_PATH = GEN / "needs_manual_remaining.json"

inv = json.loads(INV_PATH.read_text(encoding="utf-8"))
functions = inv["functions"]
enums = inv["enums"]
defines = inv["defines"]

# Phase 2 typing policy
VALUE_STRUCTS = {
    "Vector2": ["x", "y"],
    "Vector3": ["x", "y", "z"],
    "Vector4": ["x", "y", "z", "w"],
    "Rectangle": ["x", "y", "w", "h"],
    "Color": ["rgba"],
}
AUTO_LOWER_RETURN_VALUE_STRUCTS = {
    "Vector2": 2,
    "Vector3": 3,
    "Rectangle": 4,
    "Vector4": 4,
    "Matrix": 16,
    "Quaternion": 4,
    "BoundingBox": 6,
}
AUTO_LOWER_RETURN_COLOR = {
    "Color": 1,
}
MANUAL_VALUE_RET = set(VALUE_STRUCTS.keys())
MATRIX_QUATERNION = {"Matrix", "Quaternion"}
FLOAT_BUFFER_STRUCTS = {"Vector2": 2, "Vector3": 3, "Rectangle": 4, "Vector4": 4, "Matrix": 16, "Quaternion": 4, "BoundingBox": 6}

PRIMITIVE_I32 = {
    "int", "unsigned int", "long", "unsigned long", "size_t", "bool", "short", "unsigned short", "char", "unsigned char",
    "signed int", "signed long", "unsigned", "signed", "intptr_t", "uintptr_t",
}
PRIMITIVE_F32 = {"float"}
PRIMITIVE_F64 = {"double"}

LEN_HINTS = ("len", "size", "count", "capacity", "length", "bytes", "instance", "instances")
SCALAR_OUT_HINTS = ("size", "count", "index", "position", "length", "len", "written", "output", "frame", "frames")
AUTO_LOWER_VALUE_PTRS = {
    "Vector2": 2,
    "Vector3": 3,
    "Rectangle": 4,
    "Vector4": 4,
    "Matrix": 16,
    "Quaternion": 4,
    "BoundingBox": 6,
}
DOUBLE_RETURN_F32_WHITELIST = {"GetTime"}
DOUBLE_PARAM_F32_WHITELIST = {"WaitTime"}


def collapse_ws(s: str) -> str:
    return re.sub(r"\s+", " ", s or "").strip()


def strip_cv(s: str) -> str:
    s = collapse_ws(s)
    s = re.sub(r"\bconst\b", "", s)
    s = re.sub(r"\bvolatile\b", "", s)
    return collapse_ws(s)


def split_ptr(s: str):
    s = collapse_ws(s)
    ptr = s.count("*")
    base = collapse_ws(s.replace("*", ""))
    return base, ptr


def is_callback_type(t: str) -> bool:
    return "(" in t and ")" in t and "*" in t


def is_vararg_param(p: dict) -> bool:
    return p.get("decl", "").strip() == "..."


def is_len_param(name: str) -> bool:
    n = collapse_ws(name or "")
    n = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", n).lower()
    toks = [t for t in re.split(r"[^a-z0-9]+", n) if t]
    return any(t in LEN_HINTS for t in toks)


def has_len_param(all_params: list[dict], skip_param: dict | None = None) -> bool:
    for p in all_params:
        if skip_param is not None and p is skip_param:
            continue
        t = strip_cv(p.get("type_string", ""))
        base, ptr = split_ptr(t)
        if ptr != 0:
            continue
        if base not in PRIMITIVE_I32:
            continue
        if is_len_param(p.get("name_string", "")):
            return True
    return False


def is_const_pointer(type_string: str) -> bool:
    ts = collapse_ws(type_string)
    return bool(re.search(r"\bconst\b", ts))


def is_scalar_out_name(name: str) -> bool:
    n = collapse_ws(name or "")
    n = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", n).lower()
    toks = [t for t in re.split(r"[^a-z0-9]+", n) if t]
    return any(t in SCALAR_OUT_HINTS for t in toks)


def is_unload_owner_param(fname: str, param: dict) -> bool:
    if not fname.startswith("Unload"):
        return False
    t = strip_cv(param.get("type_string", ""))
    base, ptr = split_ptr(t)
    if ptr != 1:
        return False
    return base in {"int", "unsigned int", "unsigned char", "char", "float", "Color"}


def map_primitive(base: str):
    b = collapse_ws(base)
    if b in PRIMITIVE_I32:
        return "i32", None
    if b in PRIMITIVE_F32:
        return "f32", None
    if b in PRIMITIVE_F64:
        return None, "double"
    if b in {"char"}:
        return "i32", None
    return None, "unknown_primitive"


def map_return_type(ret: str, fname: str):
    r = strip_cv(ret)
    base, ptr = split_ptr(r)

    if ptr > 0:
        if base == "char":
            return "char*", None, []
        if base == "Color":
            return "void*", None, ["Color* return lowered as opaque handle"]
        if base in VALUE_STRUCTS or base in FLOAT_BUFFER_STRUCTS:
            return None, "pointer/out-param patterns", []
        if base in MATRIX_QUATERNION:
            return None, "matrix/quaternion", []
        return "void*", None, []

    if base == "void":
        return "void*", None, ["void return lowered as void* sentinel in plan; shim can still use void"]
    if base in VALUE_STRUCTS:
        return None, "returns value struct", []
    if base in MATRIX_QUATERNION:
        return None, "matrix/quaternion", []

    m, err = map_primitive(base)
    if err == "double":
        if fname in DOUBLE_RETURN_F32_WHITELIST:
            return "f32", None, ["double return downcast to f32 (precision loss)"]
        return None, "double", []
    if m:
        return m, None, []

    # Any non-value typedef struct treated as handle
    return "void*", None, ["resource/value-opaque return treated as handle"]


def try_auto_lower_value_return(ret: str):
    r = strip_cv(ret)
    base, ptr = split_ptr(r)
    if ptr != 0:
        return None
    if base in AUTO_LOWER_RETURN_VALUE_STRUCTS:
        req = AUTO_LOWER_RETURN_VALUE_STRUCTS[base]
        return {
            "shim_return": "i32",
            "extra_params": [
                {"name": "ret_out", "type": "float[]"},
                {"name": "ret_out_len", "type": "i32"},
            ],
            "notes": [
                f"return {base} lowered to out float[]; ret_out_len must be >= {req}; wrapper returns 1 on success, 0 on failure"
            ],
        }
    if base in AUTO_LOWER_RETURN_COLOR:
        req = AUTO_LOWER_RETURN_COLOR[base]
        return {
            "shim_return": "i32",
            "extra_params": [
                {"name": "ret_out", "type": "int[]"},
                {"name": "ret_out_len", "type": "i32"},
            ],
            "notes": [
                f"return {base} lowered to out int[] packed 0xRRGGBBAA; ret_out_len must be >= {req}; wrapper returns 1 on success, 0 on failure"
            ],
        }
    return None


def map_param(fname: str, param: dict, all_params: list[dict]):
    raw_t = collapse_ws(param.get("type_string", ""))
    t = strip_cv(raw_t)
    n = param.get("name_string", "") or "arg"
    base, ptr = split_ptr(t)
    notes = []

    if is_vararg_param(param):
        return None, None, None, "varargs", notes
    if param.get("is_callback") or "Callback" in t or is_callback_type(t):
        return None, None, None, "callback", notes

    # pointer params
    if ptr > 0:
        if ptr > 1:
            notes.append(f"{n}: multi-level pointer lowered as opaque void*")
            return n, "void*", "void*", None, notes

        if base == "char":
            return n, "char*", "char*", None, notes

        if is_unload_owner_param(fname, param):
            notes.append(f"{n}: unload ownership pointer lowered as void* handle")
            return n, "void*", "void*", None, notes

        # explicit buffer pointers
        if base in {"int", "unsigned int", "unsigned char", "char"}:
            has_len = has_len_param(all_params, skip_param=param)
            if has_len:
                notes.append(f"{n}: integer buffer pointer requires explicit length handling")
                return n, "int[]", "int[]", None, notes
            if not is_const_pointer(raw_t) and is_scalar_out_name(n):
                notes.append(f"{n}: scalar int out lowered to int[] + {n}_len")
                return [(n, "int[]", "int[]"), (f"{n}_len", "i32", "i32")], None, None, None, notes
            return None, None, None, "buffer without length", notes

        if base in {"float"}:
            has_len = has_len_param(all_params, skip_param=param)
            if has_len:
                notes.append(f"{n}: float buffer pointer requires explicit length handling")
                return n, "float[]", "float[]", None, notes
            if not is_const_pointer(raw_t) and is_scalar_out_name(n):
                notes.append(f"{n}: scalar float out lowered to float[] + {n}_len")
                return [(n, "float[]", "float[]"), (f"{n}_len", "i32", "i32")], None, None, None, notes
            return None, None, None, "buffer without length", notes

        if base in VALUE_STRUCTS:
            if base in AUTO_LOWER_VALUE_PTRS:
                req = AUTO_LOWER_VALUE_PTRS[base]
                if has_len_param(all_params, skip_param=param):
                    notes.append(f"{n}: {base}* lowered to float[] with existing count/len param")
                    return n, "float[]", "float[]", None, notes
                if not is_const_pointer(raw_t):
                    notes.append(f"{n}: {base} out lowered to float[] + {n}_len (>= {req})")
                    return [(n, "float[]", "float[]"), (f"{n}_len", "i32", "i32")], None, None, None, notes
            if base == "Color":
                has_len = has_len_param(all_params, skip_param=param)
                if has_len:
                    notes.append(f"{n}: Color* lowered to int[] packed 0xRRGGBBAA with existing count/len")
                    return n, "int[]", "int[]", None, notes
            return None, None, None, "pointer/out-param patterns", notes

        if base in FLOAT_BUFFER_STRUCTS:
            req = FLOAT_BUFFER_STRUCTS[base]
            if has_len_param(all_params, skip_param=param):
                notes.append(f"{n}: {base}* lowered to float[] with existing count/len param")
                return n, "float[]", "float[]", None, notes
            if not is_const_pointer(raw_t):
                notes.append(f"{n}: {base} out lowered to float[] + {n}_len (>= {req})")
                return [(n, "float[]", "float[]"), (f"{n}_len", "i32", "i32")], None, None, None, notes
            return None, None, None, "pointer/out-param patterns", notes
        if base in MATRIX_QUATERNION:
            return None, None, None, "matrix/quaternion", notes

        # handle pointer
        return n, "void*", "void*", None, notes

    # non-pointer params
    if base in VALUE_STRUCTS:
        fields = VALUE_STRUCTS[base]
        if base == "Color":
            notes.append(f"{n}: Color packed as 0xRRGGBBAA")
            return [(f"{n}_rgba", "i32", "i32")], None, None, None, notes
        flat = []
        for fld in fields:
            flat.append((f"{n}_{fld}", "f32", "f32"))
        notes.append(f"{n}: {base} flattened to scalar fields")
        return flat, None, None, None, notes

    if base in FLOAT_BUFFER_STRUCTS:
        req = FLOAT_BUFFER_STRUCTS[base]
        notes.append(f"{n}: {base} lowered to float[] + {n}_len (>= {req})")
        return [(n, "float[]", "float[]"), (f"{n}_len", "i32", "i32")], None, None, None, notes
    if base in MATRIX_QUATERNION:
        return None, None, None, "matrix/quaternion", notes

    m, err = map_primitive(base)
    if err == "double":
        if fname in DOUBLE_PARAM_F32_WHITELIST:
            notes.append(f"{n}: double downcast to f32 (precision loss)")
            return n, "f32", "f32", None, notes
        return None, None, None, "double", notes
    if m:
        return n, m, m, None, notes

    # default: handle struct/value
    notes.append(f"{n}: non-value struct treated as handle")
    return n, "void*", "void*", None, notes


plan = []
needs_manual_groups = defaultdict(list)
omitted = []

supported = 0
needs_manual = 0
omitted_count = 0

for f in functions:
    fname = f["name"]
    ret = f["return_type"]
    params = f.get("params", [])

    original_params = [p.get("decl") or f"{p.get('type_string','')} {p.get('name_string','')}".strip() for p in params]

    # callbacks/varargs are omitted
    has_cb = f.get("has_callback", False) or any("Callback" in p.get("type_string", "") for p in params)
    has_va = f.get("has_vararg", False) or any(is_vararg_param(p) for p in params)
    if has_cb or has_va:
        reason = "callback" if has_cb else "varargs"
        entry = {
            "original_name": fname,
            "original_return": ret,
            "original_params": original_params,
            "status": "OMITTED",
            "reason": reason,
        }
        plan.append(entry)
        omitted.append((fname, reason))
        omitted_count += 1
        continue

    shim_ret, ret_err, ret_notes = map_return_type(ret, fname)
    extra_return_params = []
    if ret_err:
        lowered_ret = try_auto_lower_value_return(ret)
        if lowered_ret is not None:
            shim_ret = lowered_ret["shim_return"]
            extra_return_params = lowered_ret["extra_params"]
            ret_notes.extend(lowered_ret["notes"])
            ret_err = None
        else:
            entry = {
                "original_name": fname,
                "original_return": ret,
                "original_params": original_params,
                "status": "NEEDS_MANUAL",
                "reason": ret_err,
            }
            plan.append(entry)
            needs_manual_groups[ret_err].append(fname)
            needs_manual += 1
            continue

    shim_params = []
    ffi_params = []
    notes = []
    if ret_notes:
        notes.extend(ret_notes)

    fail_reason = None
    for p in params:
        mapped = map_param(fname, p, params)
        a, b, c, perr, pnotes = mapped
        notes.extend(pnotes)
        if perr:
            fail_reason = perr
            break

        if isinstance(a, list):
            for n, pt, ft in a:
                shim_params.append({"name": n, "type": pt})
                ffi_params.append((n, ft))
        else:
            shim_params.append({"name": a, "type": b})
            ffi_params.append((a, c))

    if fail_reason:
        entry = {
            "original_name": fname,
            "original_return": ret,
            "original_params": original_params,
            "status": "NEEDS_MANUAL",
            "reason": fail_reason,
        }
        plan.append(entry)
        needs_manual_groups[fail_reason].append(fname)
        needs_manual += 1
        continue

    shim_params.extend(extra_return_params)

    # Color return note (if somehow surfaced)
    if "Color" in ret:
        notes.append("Color packed as 0xRRGGBBAA")

    entry = {
        "original_name": fname,
        "original_return": ret,
        "original_params": original_params,
        "status": "SUPPORTED",
        "reason": "supported",
        "shim_name": f"rl2_{fname}",
        "shim_return": shim_ret,
        "shim_params": shim_params,
        "notes": sorted(set(notes)),
        "_ffi_params": ffi_params,
    }
    plan.append(entry)
    supported += 1

# deterministic
plan.sort(key=lambda x: x["original_name"])

# persist plan (without internal keys)
plan_out = []
for p in plan:
    q = dict(p)
    q.pop("_ffi_params", None)
    plan_out.append(q)
PLAN_PATH.write_text(json.dumps(plan_out, indent=2) + "\n", encoding="utf-8")

inv_fn_map = {f["name"]: f for f in functions}
needs_manual_remaining = []
for p in plan_out:
    if p.get("status") != "NEEDS_MANUAL":
        continue
    fn = inv_fn_map.get(p["original_name"], {})
    needs_manual_remaining.append({
        "name": p["original_name"],
        "signature": f"{p.get('original_return', '')} {p['original_name']}({', '.join(p.get('original_params', []))})",
        "reason": p.get("reason", ""),
        "return_type": fn.get("return_type", p.get("original_return", "")),
        "params": [
            {
                "decl": prm.get("decl", ""),
                "type_string": prm.get("type_string", ""),
                "name_string": prm.get("name_string", ""),
            }
            for prm in fn.get("params", [])
        ],
    })
needs_manual_remaining.sort(key=lambda x: x["name"])
NEEDS_MANUAL_PATH.write_text(json.dumps(needs_manual_remaining, indent=2) + "\n", encoding="utf-8")

# constants file
const_lines = []
const_lines.append("// Auto-generated by tools/raylib_phase2.py")
const_lines.append("// Enum values with unknown explicit values are best-effort sequential.")
const_lines.append("")

enum_sequential_notes = []
for en in sorted(enums, key=lambda e: e["name"]):
    const_lines.append(f"// enum {en['name']}")
    cur = -1
    known_values = {}
    for it in en.get("enumerators", []):
        nm = it["name"]
        if "value" in it:
            raw = collapse_ws(str(it["value"]))
            # try numeric literal first
            mnum = re.fullmatch(r"[-+]?0[xX][0-9A-Fa-f]+|[-+]?\d+", raw)
            if mnum:
                cur = int(raw, 0)
            else:
                # very small safe expression parser for enum references and bit ops
                expr = raw
                for k, v in known_values.items():
                    expr = re.sub(rf"\b{re.escape(k)}\b", str(v), expr)
                if re.fullmatch(r"[0-9xXa-fA-F\s\(\)\|&<>+\-*/~]+", expr):
                    try:
                        cur = int(eval(expr, {"__builtins__": None}, {}))
                    except Exception:
                        cur = cur + 1
                        enum_sequential_notes.append(f"{en['name']}.{nm}={raw}")
                else:
                    cur = cur + 1
                    enum_sequential_notes.append(f"{en['name']}.{nm}={raw}")
        else:
            cur = cur + 1
        known_values[nm] = cur
        const_lines.append(f"{nm} = {cur};")
    const_lines.append("")

numeric_defines = []
non_numeric_macros = []
for d in sorted(defines, key=lambda x: x["name"]):
    name = d["name"]
    val = collapse_ws(d.get("value", ""))
    vclean = re.sub(r"[uUlLfF]+$", "", val)
    if re.fullmatch(r"[-+]?0[xX][0-9A-Fa-f]+|[-+]?\d+", vclean):
        try:
            numeric_defines.append((name, int(vclean, 0)))
            continue
        except Exception:
            pass
    non_numeric_macros.append((name, val))

const_lines.append("// numeric defines")
for n, v in numeric_defines:
    const_lines.append(f"{n} = {v};")
const_lines.append("")
CONST_PATH.write_text("\n".join(const_lines) + "\n", encoding="utf-8")

# optional shim/ffi phase2 (supported only)
ctype_map = {
    "i32": "int32_t",
    "f32": "float",
    "char*": "char*",
    "void*": "void*",
    "int[]": "void*",
    "float[]": "void*",
}
ffi_map = {
    "i32": "i32",
    "f32": "f32",
    "char*": "char*",
    "void*": "void*",
    "int[]": "void*",
    "float[]": "void*",
}

shim_lines = [
    "#ifndef GENERATED_RAYLIB_SHIM_PHASE2_H",
    "#define GENERATED_RAYLIB_SHIM_PHASE2_H",
    "",
    "#include <stdint.h>",
    "#include <stddef.h>",
    "",
    "#ifdef __cplusplus",
    "extern \"C\" {",
    "#endif",
    "",
    "// Auto-generated from generated/plan.json",
    "",
]
ffi_lines = [
    "// Auto-generated by tools/raylib_phase2.py",
    "// SUPPORTED-only signatures from generated/plan.json",
    "shim_path = \"./libraylib_disturb.so\";",
    "raylib_phase2 = ffi.load(shim_path,",
]

supported_entries = [p for p in plan if p["status"] == "SUPPORTED"]
for i, p in enumerate(supported_entries):
    ret = p["shim_return"]
    c_ret = "void" if p["original_return"].strip() == "void" else ctype_map.get(ret, "void*")

    params = p["shim_params"]
    if params:
        cplist = ", ".join(f"{ctype_map.get(x['type'],'void*')} {x['name']}" for x in params)
        fplist = ", ".join(ffi_map.get(x["type"], "void*") for x in params)
    else:
        cplist = "void"
        fplist = ""

    shim_lines.append(f"{c_ret} {p['shim_name']}({cplist});")

    comma = "," if i < len(supported_entries) - 1 else ""
    ffi_lines.append(f"  \"{ffi_map.get(ret,'void*')} {p['shim_name']}({fplist})\"{comma}")

shim_lines += ["", "#ifdef __cplusplus", "}", "#endif", "", "#endif", ""]
ffi_lines.append(");")
ffi_lines.append("")
ffi_lines.append("// NOTE: int[]/float[] in plan are lowered to void* for Disturb FFI boundary.")

SHIM_H_PATH.write_text("\n".join(shim_lines), encoding="utf-8")
FFI_PATH.write_text("\n".join(ffi_lines), encoding="utf-8")

# report phase2
needs_flat = sorted((reason, sorted(names)) for reason, names in needs_manual_groups.items())

report = []
report.append("# Phase 2 Lowering Report")
report.append("")
report.append("Generated by `tools/raylib_phase2.py`.")
report.append("")
report.append("## Totals")
report.append("")
report.append(f"- functions: {len(functions)}")
report.append(f"- supported: {supported}")
report.append(f"- needs_manual: {needs_manual}")
report.append(f"- omitted: {omitted_count}")
report.append("")
report.append("## Omitted")
report.append("")
if omitted:
    for n, r in sorted(omitted):
        report.append(f"- {n}: {r}")
else:
    report.append("- (none)")

report.append("")
report.append("## Needs Manual (Grouped)")
report.append("")
required_groups = [
    "returns value struct",
    "matrix/quaternion",
    "pointer/out-param patterns",
    "buffer without length",
    "non-numeric macros",
]

for g in required_groups:
    report.append(f"### {g}")
    if g == "non-numeric macros":
        if non_numeric_macros:
            for n, v in non_numeric_macros[:200]:
                report.append(f"- {n}: `{v}`")
        else:
            report.append("- (none)")
    else:
        names = sorted(needs_manual_groups.get(g, []))
        if names:
            for n in names:
                report.append(f"- {n}")
        else:
            report.append("- (none)")
    report.append("")

report.append("## Remaining NEEDS_MANUAL (Phase 6 input)")
report.append("")
if needs_manual_remaining:
    by_reason = defaultdict(list)
    for item in needs_manual_remaining:
        by_reason[item["reason"]].append(item)
    for reason in sorted(by_reason.keys()):
        report.append(f"### {reason}")
        for item in sorted(by_reason[reason], key=lambda x: x["name"]):
            report.append(f"- {item['name']}: `{item['signature']}`")
        report.append("")
else:
    report.append("- (none)")
    report.append("")

report.append("## Enum Value Notes")
report.append("")
if enum_sequential_notes:
    report.append("Best-effort sequential fallback was used for these enumerators:")
    for x in enum_sequential_notes:
        report.append(f"- {x}")
else:
    report.append("- No sequential fallbacks needed.")
report.append("")

report.append("## Strategy Snippets")
report.append("")
report.append("### returns value struct")
report.append("- Provide wrapper variants that fill caller-provided scalar outputs (e.g., x/y/z) or float buffers.")
report.append("- For Color, keep packed i32 0xRRGGBBAA boundary type.")
report.append("")
report.append("### matrix/quaternion")
report.append("- Introduce explicit float[16] (Matrix) and float[4] (Quaternion) conversion helpers in shim.")
report.append("- Avoid implicit layout assumptions in Disturb boundary signatures.")
report.append("")
report.append("### pointer/out-param patterns")
report.append("- Rewrite APIs to output via dedicated out buffers + explicit element counts.")
report.append("- Return i32 status codes and separate output handles/pointers.")
report.append("")
report.append("### buffer without length")
report.append("- Add shim-level length parameters; never trust implicit C-side buffer terminators unless char* text APIs.")
report.append("- Enforce size validation in shim and return error i32 on mismatch.")
report.append("")
report.append("### non-numeric macros")
report.append("- Keep non-numeric macros out of Disturb constants; replace with shim helper functions where needed.")
report.append("")

REPORT_PATH.write_text("\n".join(report) + "\n", encoding="utf-8")

print(
    f"raylib_phase2: functions={len(functions)} supported={supported} needs_manual={needs_manual} omitted={omitted_count} "
    f"plan={PLAN_PATH}"
)
