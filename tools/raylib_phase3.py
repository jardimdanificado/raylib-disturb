#!/usr/bin/env python3
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
GEN = ROOT / "generated"
TOOLS = ROOT / "tools"

PLAN_PATH = GEN / "plan.json"
INV_PATH = TOOLS / "raylib_inventory.json"

OUT_H = GEN / "raylib_shim_phase3.h"
OUT_C = GEN / "raylib_shim_phase3.c"
OUT_FFI = GEN / "raylib_ffi_phase3.dist"

VALUE_STRUCTS = {
    "Vector2": ["x", "y"],
    "Vector3": ["x", "y", "z"],
    "Vector4": ["x", "y", "z", "w"],
    "Rectangle": ["x", "y", "w", "h"],
    "Color": ["rgba"],
}
RETURN_FLOAT_STRUCT_LAYOUTS = {
    "Vector2": ["x", "y"],
    "Vector3": ["x", "y", "z"],
    "Rectangle": ["x", "y", "width", "height"],
    "Vector4": ["x", "y", "z", "w"],
    "Quaternion": ["x", "y", "z", "w"],
    "Matrix": [f"m{i}" for i in range(16)],
}
FLOAT_BUFFER_STRUCTS = {
    "Vector2": 2,
    "Vector3": 3,
    "Rectangle": 4,
    "Vector4": 4,
    "Matrix": 16,
    "Quaternion": 4,
    "BoundingBox": 6,
}
INT_BUFFER_STRUCTS = {
    "Color": 1,
}

PRIMITIVE_I32 = {
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "size_t",
    "bool",
    "short",
    "unsigned short",
    "char",
    "unsigned char",
    "signed int",
    "signed long",
    "unsigned",
    "signed",
    "intptr_t",
    "uintptr_t",
}
PRIMITIVE_F32 = {"float"}
PRIMITIVE_F64 = {"double"}

BUFFER_INT_BASES = {"int", "unsigned int", "unsigned char", "char", "short", "unsigned short"}
BUFFER_FLOAT_BASES = {"float"}
LEN_HINTS = ("len", "size", "count", "capacity", "length", "bytes", "instance", "instances")

SHIM_CTYPE_MAP = {
    "i32": "int32_t",
    "f32": "float",
    "char*": "char*",
    "void*": "void*",
    "int[]": "int32_t*",
    "float[]": "float*",
}

FFI_TYPE_MAP = {
    "i32": "i32",
    "f32": "f32",
    "char*": "char*",
    "void*": "void*",
    "int[]": "int[]",
    "float[]": "float[]",
}

PTR_HELPER_HEADER_DECLS = [
    "void* rl_ptr_identity(void* p);",
    "int32_t rl_ptr_equal(void* a, void* b);",
    "int32_t rl_ptr_hash(void* p);",
    "int32_t rl_str_len(char* s);",
    "int32_t rl_str_hash(char* s);",
    "int32_t rl_str_check_nul(char* s, int32_t max);",
]

PTR_HELPER_C_IMPL = [
    "void* rl_ptr_identity(void* p) {",
    "    return p;",
    "}",
    "",
    "int32_t rl_ptr_equal(void* a, void* b) {",
    "    return (a == b) ? 1 : 0;",
    "}",
    "",
    "int32_t rl_ptr_hash(void* p) {",
    "    uintptr_t v = (uintptr_t)p;",
    "    return (int32_t)(uint32_t)(v ^ (v >> 32));",
    "}",
    "",
    "int32_t rl_str_len(char* s) {",
    "    if (!s) return -1;",
    "    return (int32_t)strlen(s);",
    "}",
    "",
    "int32_t rl_str_hash(char* s) {",
    "    if (!s) return 0;",
    "    uint32_t h = 2166136261u;",
    "    for (const char* p = s; *p; p++) {",
    "        h ^= (uint32_t)(unsigned char)*p;",
    "        h *= 16777619u;",
    "    }",
    "    return (int32_t)h;",
    "}",
    "",
    "int32_t rl_str_check_nul(char* s, int32_t max) {",
    "    if (!s || max <= 0) return 0;",
    "    for (int32_t i = 0; i < max; i++) {",
    "        if (s[i] == '\\0') return 1;",
    "    }",
    "    return 0;",
    "}",
    "",
]

PTR_HELPER_FFI_SIGS = [
    "void* rl_ptr_identity(void*)",
    "i32 rl_ptr_equal(void*, void*)",
    "i32 rl_ptr_hash(void*)",
    "i32 rl_str_len(char*)",
    "i32 rl_str_hash(char*)",
    "i32 rl_str_check_nul(char*, i32)",
]


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


def normalize_ctype(s: str) -> str:
    s = collapse_ws(s)
    s = re.sub(r"\s*\*\s*", "*", s)
    return s


def is_len_name(name: str) -> bool:
    n = collapse_ws(name or "")
    n = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", n).lower()
    tokens = [tok for tok in re.split(r"[^a-z0-9]+", n) if tok]
    return any(tok in LEN_HINTS for tok in tokens)


def is_buffer_like_name(name: str) -> bool:
    n = (name or "").lower()
    return any(h in n for h in ("buffer", "bytes", "codepoints", "kernel", "indices", "values"))


def is_handle_value_type(base: str) -> bool:
    if base in VALUE_STRUCTS or base in INT_BUFFER_STRUCTS:
        return False
    if base in PRIMITIVE_I32 or base in PRIMITIVE_F32 or base in PRIMITIVE_F64 or base == "void":
        return False
    return True


def default_return_expr(shim_ret: str) -> str:
    if shim_ret == "i32":
        return "0"
    if shim_ret == "f32":
        return "0.0f"
    return "NULL"


def float_struct_fields(base: str) -> list[str]:
    if base == "BoundingBox":
        return ["min.x", "min.y", "min.z", "max.x", "max.y", "max.z"]
    return RETURN_FLOAT_STRUCT_LAYOUTS.get(base, [])


def expect_shim_param(func_name: str, shim_params: list[dict], idx: int, allowed: set[str], context: str):
    if idx >= len(shim_params):
        raise RuntimeError(f"{func_name}: missing shim param for {context}; expected one of {sorted(allowed)}")
    sp = shim_params[idx]
    st = sp["type"]
    if st not in allowed:
        raise RuntimeError(
            f"{func_name}: shim param type mismatch for {context}; got {st}, expected one of {sorted(allowed)}"
        )
    return sp


def c_cast_expr(orig_type: str, shim_name: str) -> str:
    return f"({normalize_ctype(orig_type)}){shim_name}"


def find_len_param_names(orig_params: list[dict]) -> set[str]:
    out = set()
    for p in orig_params:
        n = p.get("name_string", "")
        t = collapse_ws(p.get("type_string", ""))
        base, ptr = split_ptr(strip_cv(t))
        if ptr == 0 and is_len_name(n) and base in PRIMITIVE_I32:
            out.add(n)
    return out


def should_require_length_for_numeric_ptr(orig_type: str, base: str, name: str) -> bool:
    lower = collapse_ws(orig_type).lower()
    if "const" in lower:
        return True
    if base in {"unsigned char", "char", "float"}:
        return True
    if base in {"int", "unsigned int", "short", "unsigned short"}:
        return is_buffer_like_name(name)
    return False


def build_wrapper(func: dict, plan_entry: dict):
    fname = func["name"]
    orig_ret = collapse_ws(func["return_type"])
    orig_params = func.get("params", [])
    shim_name = plan_entry["shim_name"]
    shim_ret = plan_entry["shim_return"]
    shim_params = plan_entry.get("shim_params", [])
    shim_type_by_name = {sp["name"]: sp["type"] for sp in shim_params}

    c_ret = SHIM_CTYPE_MAP[shim_ret]
    c_sig_params = []
    for sp in shim_params:
        st = sp["type"]
        if st not in SHIM_CTYPE_MAP:
            raise RuntimeError(f"{fname}: unknown shim param type {st}")
        c_sig_params.append((SHIM_CTYPE_MAP[st], sp["name"], st))

    pre = []
    call_args = []
    consumed = 0

    len_param_names = find_len_param_names(orig_params)
    length_checks: list[tuple[str, str, int]] = []
    unload_free_params: list[str] = []

    def maybe_consume_synth_len(param_base_name: str):
        nonlocal consumed
        if consumed >= len(shim_params):
            return None
        nxt = shim_params[consumed]
        if nxt.get("name") == f"{param_base_name}_len" and nxt.get("type") == "i32":
            consumed += 1
            return nxt["name"]
        return None

    for i, op in enumerate(orig_params):
        otype_raw = collapse_ws(op.get("type_string", ""))
        otype = otype_raw
        oname = op.get("name_string") or f"arg{i}"

        base, ptr = split_ptr(strip_cv(otype))

        if ptr > 0:
            if ptr > 1:
                sp = expect_shim_param(fname, shim_params, consumed, {"void*"}, f"multi-level pointer param {oname}")
                call_args.append(c_cast_expr(otype, sp["name"]))
                consumed += 1
                continue

            if base == "char":
                sp = expect_shim_param(fname, shim_params, consumed, {"char*"}, f"pointer param {oname}")
                call_args.append(c_cast_expr(otype, sp["name"]))
                consumed += 1
                continue

            if base in FLOAT_BUFFER_STRUCTS:
                sp = expect_shim_param(fname, shim_params, consumed, {"float[]"}, f"{base} pointer param {oname}")
                call_args.append(c_cast_expr(otype, sp["name"]))
                consumed += 1

                synth_len = maybe_consume_synth_len(oname)
                if synth_len is not None:
                    req = FLOAT_BUFFER_STRUCTS[base]
                    length_checks.append((sp["name"], synth_len, req))
                    continue

                candidates = [n for n in len_param_names if n != oname and shim_type_by_name.get(n) == "i32"]
                if not candidates:
                    raise RuntimeError(
                        f"{fname}: generator bug - {base}* param '{oname}' missing explicit count/len"
                    )
                len_name = sorted(candidates)[0]
                length_checks.append((sp["name"], len_name, 0))
                continue

            if base in INT_BUFFER_STRUCTS:
                if consumed < len(shim_params) and shim_params[consumed]["type"] == "void*":
                    sp = expect_shim_param(fname, shim_params, consumed, {"void*"}, f"opaque {base}* param {oname}")
                    call_args.append(c_cast_expr(otype, sp["name"]))
                    consumed += 1
                    continue

                sp = expect_shim_param(fname, shim_params, consumed, {"int[]"}, f"{base} pointer param {oname}")
                call_args.append(c_cast_expr(otype, sp["name"]))
                consumed += 1

                synth_len = maybe_consume_synth_len(oname)
                if synth_len is not None:
                    req = INT_BUFFER_STRUCTS[base]
                    length_checks.append((sp["name"], synth_len, req))
                    continue

                candidates = [n for n in len_param_names if n != oname and shim_type_by_name.get(n) == "i32"]
                if not candidates:
                    raise RuntimeError(
                        f"{fname}: generator bug - {base}* param '{oname}' missing explicit count/len"
                    )
                len_name = sorted(candidates)[0]
                length_checks.append((sp["name"], len_name, 0))
                continue

            if base in BUFFER_INT_BASES:
                if consumed < len(shim_params) and shim_params[consumed]["type"] == "void*":
                    sp = expect_shim_param(fname, shim_params, consumed, {"void*"}, f"opaque int* param {oname}")
                    call_args.append(c_cast_expr(otype, sp["name"]))
                    consumed += 1
                    continue

                sp = expect_shim_param(fname, shim_params, consumed, {"int[]"}, f"int buffer param {oname}")
                call_args.append(c_cast_expr(otype, sp["name"]))
                consumed += 1

                synth_len = maybe_consume_synth_len(oname)
                if synth_len is not None:
                    length_checks.append((sp["name"], synth_len, 1))
                    continue

                if should_require_length_for_numeric_ptr(otype, base, oname):
                    candidates = [n for n in len_param_names if n != oname and shim_type_by_name.get(n) == "i32"]
                    if not candidates:
                        raise RuntimeError(
                            f"{fname}: generator bug - buffer-like param '{oname}' has no explicit length param"
                        )
                    # Deterministic: use the first length candidate lexicographically.
                    len_name = sorted(candidates)[0]
                    length_checks.append((sp["name"], len_name, 0))
                continue

            if base in BUFFER_FLOAT_BASES:
                if consumed < len(shim_params) and shim_params[consumed]["type"] == "void*":
                    sp = expect_shim_param(fname, shim_params, consumed, {"void*"}, f"opaque float* param {oname}")
                    call_args.append(c_cast_expr(otype, sp["name"]))
                    consumed += 1
                    continue

                sp = expect_shim_param(fname, shim_params, consumed, {"float[]"}, f"float buffer param {oname}")
                call_args.append(c_cast_expr(otype, sp["name"]))
                consumed += 1

                synth_len = maybe_consume_synth_len(oname)
                if synth_len is not None:
                    length_checks.append((sp["name"], synth_len, 1))
                    continue

                candidates = [n for n in len_param_names if n != oname]
                candidates = [n for n in candidates if shim_type_by_name.get(n) == "i32"]
                if not candidates:
                    raise RuntimeError(
                        f"{fname}: generator bug - buffer-like param '{oname}' has no explicit length param"
                    )
                len_name = sorted(candidates)[0]
                length_checks.append((sp["name"], len_name, 0))
                continue

            sp = expect_shim_param(fname, shim_params, consumed, {"void*"}, f"opaque pointer param {oname}")
            call_args.append(c_cast_expr(otype, sp["name"]))
            consumed += 1
            continue

        # Non-pointer params.
        if base in VALUE_STRUCTS:
            if base == "Color":
                sp = expect_shim_param(fname, shim_params, consumed, {"i32"}, f"Color param {oname}")
                pre.append(f"    Color {oname} = rl_color_from_rgba_i32({sp['name']});")
                call_args.append(oname)
                consumed += 1
                continue

            fields = VALUE_STRUCTS[base]
            field_values = []
            for field in fields:
                sp = expect_shim_param(fname, shim_params, consumed, {"f32"}, f"{base}.{field} param {oname}")
                field_values.append(sp["name"])
                consumed += 1
            pre.append(f"    {base} {oname} = {{ {', '.join(field_values)} }};")
            call_args.append(oname)
            continue

        if base in FLOAT_BUFFER_STRUCTS:
            req = FLOAT_BUFFER_STRUCTS[base]
            sp = expect_shim_param(fname, shim_params, consumed, {"float[]"}, f"{base} value param {oname}")
            consumed += 1
            len_name = maybe_consume_synth_len(oname)
            if len_name is None:
                raise RuntimeError(f"{fname}: missing synthetic length param for {base} value param {oname}")
            local_name = f"{oname}_value"
            pre.append(f"    if ({len_name} < {req}) return {default_return_expr(shim_ret)};")
            pre.append(f"    if ({sp['name']} == NULL) return {default_return_expr(shim_ret)};")
            pre.append(f"    rl_disturb_float_t* {oname}_src = (rl_disturb_float_t*)(void*){sp['name']};")
            pre.append(f"    {base} {local_name};")
            pre.append(f"    memset(&{local_name}, 0, sizeof({local_name}));")
            if base == "BoundingBox":
                pre.append(f"    {local_name}.min.x = (float){oname}_src[0];")
                pre.append(f"    {local_name}.min.y = (float){oname}_src[1];")
                pre.append(f"    {local_name}.min.z = (float){oname}_src[2];")
                pre.append(f"    {local_name}.max.x = (float){oname}_src[3];")
                pre.append(f"    {local_name}.max.y = (float){oname}_src[4];")
                pre.append(f"    {local_name}.max.z = (float){oname}_src[5];")
            else:
                for idx, fld in enumerate(float_struct_fields(base)):
                    pre.append(f"    {local_name}.{fld} = (float){oname}_src[{idx}];")
            call_args.append(local_name)
            continue

        if base in PRIMITIVE_I32:
            sp = expect_shim_param(fname, shim_params, consumed, {"i32"}, f"i32 param {oname}")
            call_args.append(c_cast_expr(otype, sp["name"]))
            consumed += 1
            continue

        if base in PRIMITIVE_F32:
            sp = expect_shim_param(fname, shim_params, consumed, {"f32"}, f"f32 param {oname}")
            call_args.append(c_cast_expr(otype, sp["name"]))
            consumed += 1
            continue

        if base in PRIMITIVE_F64:
            sp = expect_shim_param(fname, shim_params, consumed, {"f32"}, f"double param {oname}")
            call_args.append(c_cast_expr(otype, sp["name"]))
            consumed += 1
            continue

        # Opaque handle-by-value: read from void* into local value.
        sp = expect_shim_param(fname, shim_params, consumed, {"void*"}, f"handle param {oname}")
        local_name = f"{oname}_value"
        pre.append(f"    {base} {local_name};")
        pre.append(f"    memset(&{local_name}, 0, sizeof({local_name}));")
        pre.append(f"    if ({sp['name']} != NULL) {{")
        pre.append(f"        {local_name} = *(({base}*){sp['name']});")
        pre.append("    }")
        call_args.append(local_name)

        if fname.startswith("Unload"):
            unload_free_params.append(sp["name"])

        consumed += 1

    # Runtime pointer/length guards for array-like params.
    # If len > 0 then ptr must not be NULL; len must be >= 0.
    for ptr_name, len_name, min_req in sorted(set(length_checks)):
        if min_req > 0:
            pre.append(f"    if ({len_name} < {min_req}) return {default_return_expr(shim_ret)};")
            pre.append(f"    if ({ptr_name} == NULL) return {default_return_expr(shim_ret)};")
        else:
            pre.append(f"    if ({len_name} < 0) return {default_return_expr(shim_ret)};")
            pre.append(f"    if ({len_name} > 0 && {ptr_name} == NULL) return {default_return_expr(shim_ret)};")

    call_expr = f"{fname}({', '.join(call_args)})"

    ret_base, ret_ptr = split_ptr(strip_cv(orig_ret))
    body = []
    body.extend(pre)

    ret_out_ptr = None
    ret_out_len = None
    ret_out_kind = None
    if (
        ret_ptr == 0
        and ret_base in FLOAT_BUFFER_STRUCTS
        and consumed < len(shim_params)
        and shim_params[consumed].get("name") == "ret_out"
        and shim_params[consumed].get("type") == "float[]"
    ):
        sp = expect_shim_param(fname, shim_params, consumed, {"float[]"}, f"{ret_base} return out buffer")
        ret_out_ptr = sp["name"]
        ret_out_kind = "float"
        consumed += 1
        sp = expect_shim_param(fname, shim_params, consumed, {"i32"}, f"{ret_base} return out length")
        ret_out_len = sp["name"]
        consumed += 1
    elif (
        ret_ptr == 0
        and ret_base in INT_BUFFER_STRUCTS
        and consumed < len(shim_params)
        and shim_params[consumed].get("name") == "ret_out"
        and shim_params[consumed].get("type") == "int[]"
    ):
        sp = expect_shim_param(fname, shim_params, consumed, {"int[]"}, f"{ret_base} return out buffer")
        ret_out_ptr = sp["name"]
        ret_out_kind = "int"
        consumed += 1
        sp = expect_shim_param(fname, shim_params, consumed, {"i32"}, f"{ret_base} return out length")
        ret_out_len = sp["name"]
        consumed += 1

    if consumed != len(shim_params):
        raise RuntimeError(
            f"{fname}: unconsumed shim params: consumed={consumed}, total={len(shim_params)}"
        )

    if ret_base == "void" and ret_ptr == 0:
        body.append(f"    {call_expr};")
        for p in unload_free_params:
            body.append(f"    if ({p} != NULL) free({p});")
        body.append("    return NULL;")
    elif ret_out_kind == "float" and ret_base in FLOAT_BUFFER_STRUCTS:
        fields = float_struct_fields(ret_base)
        req = FLOAT_BUFFER_STRUCTS[ret_base]
        body.append(f"    if ({ret_out_len} < {req}) return 0;")
        body.append(f"    if ({ret_out_ptr} == NULL) return 0;")
        body.append(f"    {ret_base} rl_value = {call_expr};")
        body.append(f"    rl_disturb_float_t* rl_out = (rl_disturb_float_t*)(void*){ret_out_ptr};")
        if ret_base == "BoundingBox":
            body.append("    rl_out[0] = (rl_disturb_float_t)rl_value.min.x;")
            body.append("    rl_out[1] = (rl_disturb_float_t)rl_value.min.y;")
            body.append("    rl_out[2] = (rl_disturb_float_t)rl_value.min.z;")
            body.append("    rl_out[3] = (rl_disturb_float_t)rl_value.max.x;")
            body.append("    rl_out[4] = (rl_disturb_float_t)rl_value.max.y;")
            body.append("    rl_out[5] = (rl_disturb_float_t)rl_value.max.z;")
        else:
            for idx, field in enumerate(fields):
                body.append(f"    rl_out[{idx}] = (rl_disturb_float_t)rl_value.{field};")
        body.append("    return 1;")
    elif ret_out_kind == "int" and ret_base in INT_BUFFER_STRUCTS:
        req = INT_BUFFER_STRUCTS[ret_base]
        body.append(f"    if ({ret_out_len} < {req}) return 0;")
        body.append(f"    if ({ret_out_ptr} == NULL) return 0;")
        body.append(f"    {ret_base} rl_value = {call_expr};")
        body.append(f"    rl_disturb_int_t* rl_out = (rl_disturb_int_t*)(void*){ret_out_ptr};")
        if ret_base == "Color":
            body.append("    rl_out[0] = (rl_disturb_int_t)rl_rgba_i32_from_color(rl_value);")
        else:
            body.append("    rl_out[0] = 0;")
        body.append("    return 1;")
    elif ret_ptr > 0:
        if ret_base == "char":
            body.append(f"    return (char*){call_expr};")
        else:
            body.append(f"    return (void*){call_expr};")
    elif ret_base in PRIMITIVE_I32:
        if ret_base == "bool":
            body.append(f"    return {call_expr} ? 1 : 0;")
        else:
            body.append(f"    return (int32_t){call_expr};")
    elif ret_base in PRIMITIVE_F32:
        body.append(f"    return (float){call_expr};")
    elif ret_base in PRIMITIVE_F64:
        if shim_ret == "f32":
            body.append(f"    return (float){call_expr};")
        else:
            raise RuntimeError(f"{fname}: unexpected supported double return")
    elif ret_base in VALUE_STRUCTS:
        raise RuntimeError(f"{fname}: unexpected supported VALUE return ({ret_base})")
    elif is_handle_value_type(ret_base):
        body.append(f"    {ret_base} rl_value = {call_expr};")
        body.append(f"    {ret_base}* rl_heap = ({ret_base}*)malloc(sizeof({ret_base}));")
        body.append("    if (rl_heap == NULL) return NULL;")
        body.append("    *rl_heap = rl_value;")
        body.append("    return (void*)rl_heap;")
    else:
        raise RuntimeError(f"{fname}: unsupported return type resolution for '{orig_ret}'")

    return {
        "original_name": fname,
        "shim_name": shim_name,
        "shim_return": shim_ret,
        "c_return": c_ret,
        "c_sig_params": c_sig_params,
        "body": body,
    }


def generate_header(wrappers: list[dict]):
    lines = [
        "#ifndef GENERATED_RAYLIB_SHIM_PHASE3_H",
        "#define GENERATED_RAYLIB_SHIM_PHASE3_H",
        "",
        "#include <stdint.h>",
        "",
        "#ifdef __cplusplus",
        "extern \"C\" {",
        "#endif",
        "",
        "// Auto-generated by tools/raylib_phase3.py from generated/plan.json",
        "",
    ]

    for w in wrappers:
        if w["c_sig_params"]:
            plist = ", ".join(f"{ct} {pn}" for ct, pn, _ in w["c_sig_params"])
        else:
            plist = "void"
        lines.append(f"{w['c_return']} {w['shim_name']}({plist});")

    lines.append("")
    lines.append("// Pointer roundtrip helpers used by FFI conformance tests.")
    lines.extend(PTR_HELPER_HEADER_DECLS)

    lines += [
        "",
        "#ifdef __cplusplus",
        "}",
        "#endif",
        "",
        "#endif",
        "",
    ]

    OUT_H.write_text("\n".join(lines), encoding="utf-8")


def generate_c(wrappers: list[dict], need_color_pack_return: bool):
    lines = [
        "// Auto-generated by tools/raylib_phase3.py from generated/plan.json",
        "#include <stdlib.h>",
        "#include <stdint.h>",
        "#include <string.h>",
        '#include "raylib.h"',
        '#include "raylib_shim_phase3.h"',
        "",
        "typedef intptr_t rl_disturb_int_t;",
        "#if INTPTR_MAX == INT64_MAX",
        "typedef double rl_disturb_float_t;",
        "#else",
        "typedef float rl_disturb_float_t;",
        "#endif",
        "",
        "static inline Color rl_color_from_rgba_i32(int32_t rgba) {",
        "    Color c;",
        "    c.r = (uint8_t)((rgba >> 24) & 0xFF);",
        "    c.g = (uint8_t)((rgba >> 16) & 0xFF);",
        "    c.b = (uint8_t)((rgba >> 8) & 0xFF);",
        "    c.a = (uint8_t)(rgba & 0xFF);",
        "    return c;",
        "}",
        "",
    ]

    if need_color_pack_return:
        lines += [
            "static inline int32_t rl_rgba_i32_from_color(Color c) {",
            "    return ((int32_t)c.r << 24) | ((int32_t)c.g << 16) | ((int32_t)c.b << 8) | (int32_t)c.a;",
            "}",
            "",
        ]

    for w in wrappers:
        if w["c_sig_params"]:
            plist = ", ".join(f"{ct} {pn}" for ct, pn, _ in w["c_sig_params"])
        else:
            plist = "void"
        lines.append(f"{w['c_return']} {w['shim_name']}({plist}) {{")
        for body_line in w["body"]:
            lines.append(body_line)
        lines.append("}")
        lines.append("")

    lines.extend(PTR_HELPER_C_IMPL)

    OUT_C.write_text("\n".join(lines), encoding="utf-8")


def generate_ffi(wrappers: list[dict]):
    lines = [
        "// Auto-generated by tools/raylib_phase3.py",
        "// SUPPORTED-only signatures from generated/plan.json",
        'eval(read("generated/raylib_constants.dist"));',
        'shim_path = read("disturb_bindings/shim_path_phase3.bin");',
        "if (shim_path == null) {",
        '  shim_path = "./libraylib_disturb_phase3.so";',
        "}",
        "raylib_phase3 = ffi.load(shim_path,",
    ]

    all_sigs = []
    for w in wrappers:
        ret = FFI_TYPE_MAP[w["shim_return"]]
        params = ", ".join(FFI_TYPE_MAP[st] for _, _, st in w["c_sig_params"])
        all_sigs.append(f"{ret} {w['shim_name']}({params})")
    all_sigs.extend(PTR_HELPER_FFI_SIGS)

    for idx, sig in enumerate(all_sigs):
        comma = "," if idx < len(all_sigs) - 1 else ""
        lines.append(f'  "{sig}"{comma}')

    lines.append(");")
    lines.append("")

    OUT_FFI.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    if not PLAN_PATH.exists():
        print(f"missing {PLAN_PATH}", file=sys.stderr)
        return 1
    if not INV_PATH.exists():
        print(f"missing {INV_PATH}", file=sys.stderr)
        return 1

    plan = json.loads(PLAN_PATH.read_text(encoding="utf-8"))
    inv = json.loads(INV_PATH.read_text(encoding="utf-8"))
    inv_map = {f["name"]: f for f in inv["functions"]}

    supported = [p for p in plan if p["status"] == "SUPPORTED"]
    supported.sort(key=lambda x: x["shim_name"])

    wrappers = []
    need_color_pack_return = True

    for p in supported:
        name = p["original_name"]
        if name not in inv_map:
            raise RuntimeError(f"{name}: missing from inventory")
        func = inv_map[name]
        wrapper = build_wrapper(func, p)
        wrappers.append(wrapper)

    generate_header(wrappers)
    generate_c(wrappers, need_color_pack_return)
    generate_ffi(wrappers)

    print(
        f"raylib_phase3: supported={len(wrappers)} "
        f"header={OUT_H} c={OUT_C} ffi={OUT_FFI}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
