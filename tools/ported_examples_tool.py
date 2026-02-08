#!/usr/bin/env python3
"""Manage examples_raylib_port manifest and generated Disturb runners."""

from __future__ import annotations

import argparse
import json
import pathlib
import sys
from collections import defaultdict

ROOT = pathlib.Path(__file__).resolve().parent.parent
PORT_DIR = ROOT / "examples_raylib_port"
MANIFEST_PATH = PORT_DIR / "manifest.json"
RUN_ALL_PATH = PORT_DIR / "run_all.dist"
RUN_FAST_PATH = PORT_DIR / "run_fast.dist"

REQUIRED_KEYS = {
    "name",
    "category",
    "path",
    "requires_display",
    "requires_assets",
    "requires_audio",
    "fast",
}


def load_manifest() -> list[dict]:
    data = json.loads(MANIFEST_PATH.read_text(encoding="utf-8"))
    if not isinstance(data, list):
        raise ValueError("manifest.json must contain a JSON array")

    names = set()
    for idx, item in enumerate(data):
        if not isinstance(item, dict):
            raise ValueError(f"manifest entry #{idx} must be an object")
        missing = REQUIRED_KEYS.difference(item)
        if missing:
            missing_s = ", ".join(sorted(missing))
            raise ValueError(f"manifest entry #{idx} missing keys: {missing_s}")
        unknown = set(item).difference(REQUIRED_KEYS)
        if unknown:
            unknown_s = ", ".join(sorted(unknown))
            raise ValueError(f"manifest entry #{idx} has unknown keys: {unknown_s}")

        name = str(item["name"])
        path = str(item["path"])
        if name in names:
            raise ValueError(f"duplicate example name in manifest: {name}")
        names.add(name)

        if not path.startswith("examples_raylib_port/"):
            raise ValueError(f"manifest path must be repo-relative under examples_raylib_port: {path}")

        full_path = ROOT / path
        if not full_path.exists():
            raise ValueError(f"manifest path does not exist: {path}")

        if not isinstance(item["requires_assets"], list):
            raise ValueError(f"manifest {name}: requires_assets must be a list")

    return data


def _runner_header(title: str) -> list[str]:
    return [
        f"// {title}",
        "",
        "pass_count = 0;",
        "pass_headless_count = 0;",
        "pass_windowed_count = 0;",
        "skip_count = 0;",
        "fail_count = 0;",
        "",
        "display_line = (path, label){",
        "  println(label + \" \" + path);",
        "};",
        "",
        "run_example = (name, path){",
        "  log = \"/tmp/raylib_port_\" + name + \".log\";",
        "  system(\"rm -f \" + log);",
        "",
        "  cmd = \"./disturb/disturb \" + path + \" >\" + log + \" 2>&1\";",
        "  code = system(cmd);",
        "",
        "  if (code != 0) {",
        "    display_line(name, \"FAIL\");",
        "    println(read(log));",
        "    return -1;",
        "  }",
        "",
        "  if (system(\"rg -q '^FAIL ' \" + log) == 0) {",
        "    display_line(name, \"FAIL\");",
        "    println(read(log));",
        "    return -1;",
        "  }",
        "",
        "  if (system(\"rg -q '^PASS_HEADLESS ' \" + log) == 0) {",
        "    display_line(name, \"PASS_HEADLESS\");",
        "    return 2;",
        "  }",
        "",
        "  if (system(\"rg -q '^PASS_WINDOWED ' \" + log) == 0) {",
        "    display_line(name, \"PASS_WINDOWED\");",
        "    return 1;",
        "  }",
        "",
        "  if (system(\"rg -q '^PASS ' \" + log) == 0) {",
        "    display_line(name, \"PASS\");",
        "    return 1;",
        "  }",
        "",
        "  if (system(\"rg -q '^SKIP ' \" + log) == 0) {",
        "    display_line(name, \"SKIP\");",
        "    return 0;",
        "  }",
        "",
        "  display_line(name, \"FAIL\");",
        "  println(\"No PASS/SKIP/FAIL marker found in output:\");",
        "  println(read(log));",
        "  return -1;",
        "};",
        "",
    ]


def _runner_body(entries: list[dict]) -> list[str]:
    lines: list[str] = []
    for entry in entries:
        name = entry["name"]
        path = entry["path"]
        lines.extend(
            [
                f"status = run_example(\"{name}\", \"{path}\");",
                "if (status == 2) { pass_count = pass_count + 1; pass_headless_count = pass_headless_count + 1; }",
                "else if (status == 1) { pass_count = pass_count + 1; pass_windowed_count = pass_windowed_count + 1; }",
                "else if (status == 0) { skip_count = skip_count + 1; }",
                "else { fail_count = fail_count + 1; }",
                "",
            ]
        )
    return lines


def _runner_footer() -> list[str]:
    return [
        "println(\"\\n=== raylib official ports summary ===\");",
        "println(\"PASS_TOTAL: \" + pass_count);",
        "println(\"PASS_HEADLESS: \" + pass_headless_count);",
        "println(\"PASS_WINDOWED: \" + pass_windowed_count);",
        "println(\"SKIP: \" + skip_count);",
        "println(\"FAIL: \" + fail_count);",
        "",
        "if (fail_count > 0) {",
        "  println(\"FAIL run_all\");",
        "  if (system(\"test -n \\\"$PORT_RUN_NO_KILL\\\"\") != 0) {",
        "    system(\"kill -TERM $PPID\");",
        "  }",
        "}",
        "else {",
        "  println(\"PASS run_all\");",
        "}",
        "",
    ]


def render_runner(entries: list[dict], title: str) -> str:
    lines = _runner_header(title)
    lines.extend(_runner_body(entries))
    lines.extend(_runner_footer())
    return "\n".join(lines)


def write_if_changed(path: pathlib.Path, content: str) -> None:
    current = path.read_text(encoding="utf-8") if path.exists() else None
    if current != content:
        path.write_text(content, encoding="utf-8")


def cmd_generate(entries: list[dict]) -> int:
    fast_entries = [entry for entry in entries if bool(entry["fast"])]
    if not fast_entries:
        raise ValueError("manifest has no fast=true entries")

    run_all = render_runner(entries, "Run all official raylib example ports and summarize PASS/SKIP/FAIL.")
    run_fast = render_runner(
        fast_entries,
        "Run fast headless-capable subset of official raylib example ports and summarize PASS/SKIP/FAIL.",
    )

    write_if_changed(RUN_ALL_PATH, run_all)
    write_if_changed(RUN_FAST_PATH, run_fast)
    return 0


def cmd_list(entries: list[dict], only_fast: bool) -> int:
    selected = [entry for entry in entries if (bool(entry["fast"]) if only_fast else True)]
    grouped: dict[str, list[dict]] = defaultdict(list)
    for entry in selected:
        grouped[entry["category"]].append(entry)

    total = 0
    mode = "fast subset" if only_fast else "all"
    print(f"ported examples ({mode}):")
    for category in sorted(grouped):
        print(f"[{category}]")
        for entry in grouped[category]:
            req = []
            if bool(entry["requires_display"]):
                req.append("display")
            if bool(entry["requires_audio"]):
                req.append("audio")
            if entry["requires_assets"]:
                req.append("assets")
            req_s = ", ".join(req) if req else "none"
            print(f"- {entry['name']} ({entry['path']}) requires: {req_s}")
            total += 1
    print(f"total: {total}")
    return 0


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--generate", action="store_true", help="generate run_all.dist and run_fast.dist from manifest")
    parser.add_argument("--list", action="store_true", help="print full list of ported examples grouped by category")
    parser.add_argument("--list-fast", action="store_true", help="print fast subset grouped by category")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    if not (args.generate or args.list or args.list_fast):
        print("Nothing to do; use --generate, --list, or --list-fast", file=sys.stderr)
        return 2

    entries = load_manifest()

    if args.generate:
        cmd_generate(entries)
    if args.list:
        cmd_list(entries, only_fast=False)
    if args.list_fast:
        cmd_list(entries, only_fast=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
