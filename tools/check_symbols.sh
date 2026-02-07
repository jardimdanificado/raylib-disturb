#!/usr/bin/env bash
set -euo pipefail

LIB="./libraylib_disturb.so"

if [[ ! -f "$LIB" ]]; then
  echo "Missing $LIB. Build first with: make"
  exit 1
fi

if command -v nm >/dev/null 2>&1; then
  nm -D "$LIB" | grep ' rl_' || true
elif command -v objdump >/dev/null 2>&1; then
  objdump -T "$LIB" | grep ' rl_' || true
else
  echo "Neither nm nor objdump found"
  exit 1
fi
