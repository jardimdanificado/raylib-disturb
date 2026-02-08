#!/usr/bin/env python3
import json
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
PLAN_PATH = ROOT / "generated" / "plan.json"
SO_PATH = ROOT / "libraylib_disturb_phase3.so"


def load_expected(plan_path: pathlib.Path) -> list[str]:
    plan = json.loads(plan_path.read_text(encoding="utf-8"))
    out = sorted(p["shim_name"] for p in plan if p.get("status") == "SUPPORTED")
    return out


def run_cmd(args: list[str]) -> subprocess.CompletedProcess[str]:
    return subprocess.run(args, check=False, text=True, capture_output=True)


def exported_symbols(so_path: pathlib.Path) -> set[str]:
    nm = run_cmd(["nm", "-D", "--defined-only", str(so_path)])
    if nm.returncode == 0:
        syms = set()
        for line in nm.stdout.splitlines():
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) >= 3:
                syms.add(parts[-1])
            elif len(parts) == 2:
                syms.add(parts[-1])
        return syms

    objdump = run_cmd(["objdump", "-T", str(so_path)])
    if objdump.returncode != 0:
        raise RuntimeError(
            "failed to inspect symbols: both 'nm -D --defined-only' and 'objdump -T' failed"
        )

    syms = set()
    for line in objdump.stdout.splitlines():
        line = line.strip()
        if not line or " .text " not in f" {line} ":
            continue
        parts = line.split()
        if parts:
            sym = parts[-1]
            if re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", sym):
                syms.add(sym)
    return syms


def main() -> int:
    if not PLAN_PATH.exists():
        print(f"missing plan file: {PLAN_PATH}", file=sys.stderr)
        return 1
    if not SO_PATH.exists():
        print(f"missing shim shared object: {SO_PATH}", file=sys.stderr)
        return 1

    expected = load_expected(PLAN_PATH)
    exported = exported_symbols(SO_PATH)
    missing = [sym for sym in expected if sym not in exported]

    print(f"verify_phase3_symbols: expected={len(expected)} exported={len(exported)}")
    if missing:
        print(f"missing symbols: {len(missing)}")
        for sym in missing:
            print(f"- {sym}")
        return 1

    print("verify_phase3_symbols: OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
