#!/usr/bin/env python3
"""ABI audit: cross-check plan.json, raylib_inventory.json,
   raylib_shim_phase3.h prototypes, and raylib_ffi_phase3.dist declarations.

   Usage: python tools/abi_audit.py [wrapper_name ...]
   If no names given, audits all SUPPORTED wrappers.
"""
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
GEN = ROOT / "generated"
TOOLS = ROOT / "tools"

PLAN_PATH = GEN / "plan.json"
INV_PATH = TOOLS / "raylib_inventory.json"
HEADER_PATH = GEN / "raylib_shim_phase3.h"
FFI_PATH = GEN / "raylib_ffi_phase3.dist"

# Map from plan shim types to expected C header types
SHIM_TO_C = {
    "i32": "int32_t",
    "f32": "float",
    "char*": "char*",
    "void*": "void*",
    "int[]": "int32_t*",
    "float[]": "float*",
}

# Map from plan shim types to expected FFI types
SHIM_TO_FFI = {
    "i32": "i32",
    "f32": "f32",
    "char*": "char*",
    "void*": "void*",
    "int[]": "int[]",
    "float[]": "float[]",
}


def parse_header_prototypes(path: pathlib.Path) -> dict:
    """Parse C header prototypes into {name: {"return": str, "params": [str]}}"""
    text = path.read_text(encoding="utf-8")
    protos = {}
    for m in re.finditer(
        r"^(\w[\w\s\*]+?)\s+(rl2_\w+|rl_\w+)\(([^)]*)\)\s*;",
        text,
        re.MULTILINE,
    ):
        ret = re.sub(r"\s+", " ", m.group(1)).strip()
        name = m.group(2)
        params_raw = m.group(3).strip()
        if params_raw == "void" or params_raw == "":
            params = []
        else:
            params = [re.sub(r"\s+", " ", p).strip() for p in params_raw.split(",")]
        protos[name] = {"return": ret, "params": params}
    return protos


def parse_ffi_signatures(path: pathlib.Path) -> dict:
    """Parse FFI .dist file into {name: {"return": str, "params": [str]}}"""
    text = path.read_text(encoding="utf-8")
    sigs = {}
    for m in re.finditer(r'"(\S+)\s+(\w+)\(([^)]*)\)"', text):
        ret = m.group(1)
        name = m.group(2)
        params_raw = m.group(3).strip()
        if params_raw == "":
            params = []
        else:
            params = [p.strip() for p in params_raw.split(",")]
        sigs[name] = {"return": ret, "params": params}
    return sigs


def extract_c_type(param_str: str) -> str:
    """Extract just the C type from a 'type name' declaration."""
    param_str = param_str.strip()
    # Remove parameter name: everything after last space that isn't a *
    m = re.match(r"^(.*?)\s+(\w+)$", param_str)
    if m:
        return m.group(1).strip()
    return param_str


def audit(names: list[str] | None = None) -> int:
    plan = json.loads(PLAN_PATH.read_text(encoding="utf-8"))
    inv = json.loads(INV_PATH.read_text(encoding="utf-8"))
    inv_map = {f["name"]: f for f in inv["functions"]}

    header_protos = parse_header_prototypes(HEADER_PATH)
    ffi_sigs = parse_ffi_signatures(FFI_PATH)

    supported = [p for p in plan if p["status"] == "SUPPORTED"]
    plan_map = {p["shim_name"]: p for p in supported}

    if names:
        targets = names
    else:
        targets = sorted(plan_map.keys())

    errors = []
    warnings = []
    checked = 0

    for shim_name in targets:
        if shim_name not in plan_map:
            errors.append(f"{shim_name}: not found in plan.json (SUPPORTED)")
            continue

        pe = plan_map[shim_name]
        orig_name = pe["original_name"]
        checked += 1

        # 1. Check plan ↔ inventory consistency
        if orig_name not in inv_map:
            errors.append(f"{shim_name}: original '{orig_name}' missing from inventory")
            continue

        inv_func = inv_map[orig_name]
        plan_param_count = len(pe.get("shim_params", []))

        # 2. Check plan ↔ header consistency
        if shim_name not in header_protos:
            errors.append(f"{shim_name}: missing from header {HEADER_PATH.name}")
            continue

        hp = header_protos[shim_name]
        expected_c_ret = SHIM_TO_C.get(pe["shim_return"])
        if expected_c_ret and hp["return"] != expected_c_ret:
            errors.append(
                f"{shim_name}: return type mismatch: "
                f"plan={pe['shim_return']}→{expected_c_ret}, header={hp['return']}"
            )

        # Check param count
        if len(hp["params"]) != plan_param_count:
            errors.append(
                f"{shim_name}: param count mismatch: "
                f"plan={plan_param_count}, header={len(hp['params'])}"
            )
        else:
            # Check param types match
            for i, sp in enumerate(pe.get("shim_params", [])):
                expected_ct = SHIM_TO_C.get(sp["type"])
                if expected_ct and i < len(hp["params"]):
                    actual_ct = extract_c_type(hp["params"][i])
                    if actual_ct != expected_ct:
                        errors.append(
                            f"{shim_name}: param[{i}] '{sp['name']}' type mismatch: "
                            f"plan={sp['type']}→{expected_ct}, header={actual_ct}"
                        )

        # 3. Check plan ↔ FFI consistency
        if shim_name not in ffi_sigs:
            errors.append(f"{shim_name}: missing from FFI {FFI_PATH.name}")
            continue

        fs = ffi_sigs[shim_name]
        expected_ffi_ret = SHIM_TO_FFI.get(pe["shim_return"])
        if expected_ffi_ret and fs["return"] != expected_ffi_ret:
            errors.append(
                f"{shim_name}: FFI return type mismatch: "
                f"plan={pe['shim_return']}→{expected_ffi_ret}, ffi={fs['return']}"
            )

        if len(fs["params"]) != plan_param_count:
            errors.append(
                f"{shim_name}: FFI param count mismatch: "
                f"plan={plan_param_count}, ffi={len(fs['params'])}"
            )
        else:
            for i, sp in enumerate(pe.get("shim_params", [])):
                expected_ft = SHIM_TO_FFI.get(sp["type"])
                if expected_ft and i < len(fs["params"]):
                    actual_ft = fs["params"][i]
                    if actual_ft != expected_ft:
                        errors.append(
                            f"{shim_name}: FFI param[{i}] '{sp['name']}' type mismatch: "
                            f"plan={sp['type']}→{expected_ft}, ffi={actual_ft}"
                        )

        # 4. Warn about char* params (string NUL-termination risk)
        for sp in pe.get("shim_params", []):
            if sp["type"] == "char*":
                # This is expected now - just informational
                pass

    # Summary
    print(f"ABI audit: checked {checked} wrappers")
    if warnings:
        print(f"\n  WARNINGS ({len(warnings)}):")
        for w in warnings:
            print(f"    WARN: {w}")
    if errors:
        print(f"\n  ERRORS ({len(errors)}):")
        for e in errors:
            print(f"    ERROR: {e}")
        return 1
    else:
        print("  All checks PASSED")
        return 0


def main() -> int:
    for path in (PLAN_PATH, INV_PATH, HEADER_PATH, FFI_PATH):
        if not path.exists():
            print(f"missing: {path}", file=sys.stderr)
            return 1

    names = sys.argv[1:] if len(sys.argv) > 1 else None
    return audit(names)


if __name__ == "__main__":
    raise SystemExit(main())
