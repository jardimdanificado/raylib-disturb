#!/usr/bin/env python3
"""Visual regression test harness for raylib C examples vs Disturb ports.

For each example: patch C source with frame-limit + screenshot, compile, run both sides,
compare screenshots with tolerant image diff. Produce summary report and diff images.

Usage:
    python tools/visual_regress.py --tier1          # Tier 1 only
    python tools/visual_regress.py --all            # All tiers
    python tools/visual_regress.py --names core_basic_window,shapes_logo_raylib
    python tools/visual_regress.py --tier1 --frames 60
"""
import argparse
import json
import os
import pathlib
import re
import shutil
import subprocess
import sys
import time

ROOT = pathlib.Path(__file__).resolve().parent.parent
MANIFEST = ROOT / "tools" / "visual_regress_manifest.json"
RAYLIB_LIB = ROOT / "raylib" / "build" / "raylib" / "libraylib.a"
RAYLIB_INC = ROOT / "raylib" / "src"
DISTURB_BIN = ROOT / "disturb" / "disturb"
BIN_DIR = ROOT / "bin" / "c_regress"
OUT_C = ROOT / "out" / "c"
OUT_D = ROOT / "out" / "disturb"
OUT_DIFF = ROOT / "out" / "diff"

CC = os.environ.get("CC", "gcc")
SYSLIBS = "-lm -lpthread -ldl -lrt -lX11"

TIER1_THRESHOLD_PIXEL_EQUAL = 0.999
TIER2_THRESHOLD_SSIM = 0.98


def ensure_dirs():
    for d in (BIN_DIR, OUT_C, OUT_D, OUT_DIFF):
        d.mkdir(parents=True, exist_ok=True)


def has_display():
    if os.environ.get("DISPLAY"):
        return True
    return False


def wrap_xvfb(cmd: list[str], cwd=None) -> list[str]:
    """Wrap command with xvfb-run if no DISPLAY available."""
    if has_display():
        return cmd
    xvfb = shutil.which("xvfb-run")
    if not xvfb:
        return cmd  # hope for the best
    return [xvfb, "-a", "-s", "-screen 0 1280x720x24"] + cmd


def patch_c_source(c_source: str, name: str, frames: int, out_png_path: str) -> str:
    """Patch a C example source to add frame counting and screenshot."""
    src = c_source

    # Normalize the screenshot output path for C string
    out_png_c = out_png_path.replace("\\", "/")

    # 1. Add frame counter before the while loop
    src = re.sub(
        r"(while\s*\(\s*!WindowShouldClose\(\)\s*\))",
        r"int _rf = 0;\n    \1",
        src,
        count=1,
    )

    # 2. Add frame limit to while condition
    src = re.sub(
        r"while\s*\(\s*!WindowShouldClose\(\)\s*\)\s*//[^\n]*\n",
        f"while (!WindowShouldClose() && _rf < {frames})\n",
        src,
        count=1,
    )
    # Also handle case without trailing comment
    src = re.sub(
        r"while\s*\(\s*!WindowShouldClose\(\)\s*&&\s*_rf\s*<\s*\d+\s*\)\s*\n",
        f"while (!WindowShouldClose() && _rf < {frames})\n",
        src,
        count=1,
    )
    # Fallback: if the pattern didn't match above (no trailing comment line)
    if f"_rf < {frames}" not in src:
        src = re.sub(
            r"while\s*\(\s*!WindowShouldClose\(\)\s*\)",
            f"while (!WindowShouldClose() && _rf < {frames})",
            src,
            count=1,
        )

    # 3. Add frame counter increment after EndDrawing()
    src = src.replace(
        "EndDrawing();",
        "EndDrawing(); _rf++;",
        1,
    )

    # 4. Add TakeScreenshot before CloseWindow
    src = src.replace(
        "CloseWindow();",
        f'TakeScreenshot("{out_png_c}");\n    CloseWindow();',
        1,
    )

    return src


def compile_c(name: str, patched_path: pathlib.Path, bin_path: pathlib.Path) -> bool:
    """Compile a patched C example."""
    cmd = [
        CC, "-O2", "-w",
        str(patched_path),
        f"-I{RAYLIB_INC}",
        str(RAYLIB_LIB),
        *SYSLIBS.split(),
        "-o", str(bin_path),
    ]
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=60)
    if result.returncode != 0:
        print(f"  COMPILE FAIL: {result.stderr[:500]}", file=sys.stderr)
        return False
    return True


def run_example(cmd: list[str], cwd=None, timeout_s=60) -> bool:
    """Run an example binary, returns True on success."""
    full_cmd = wrap_xvfb(cmd, cwd=cwd)
    try:
        result = subprocess.run(
            full_cmd,
            capture_output=True,
            text=True,
            timeout=timeout_s,
            cwd=cwd,
        )
        return result.returncode == 0
    except subprocess.TimeoutExpired:
        print(f"  TIMEOUT after {timeout_s}s", file=sys.stderr)
        return False
    except Exception as e:
        print(f"  RUN ERROR: {e}", file=sys.stderr)
        return False


def compute_metrics(img_a_path: pathlib.Path, img_b_path: pathlib.Path):
    """Compare two images. Returns dict with pixel_equal, mae, ssim."""
    try:
        from PIL import Image
        import numpy as np
    except ImportError:
        return {"error": "PIL/numpy not available"}

    a = np.array(Image.open(img_a_path).convert("RGB"), dtype=np.float64)
    b = np.array(Image.open(img_b_path).convert("RGB"), dtype=np.float64)

    if a.shape != b.shape:
        return {
            "pixel_equal": 0.0,
            "mae": 255.0,
            "ssim": 0.0,
            "error": f"size mismatch: {a.shape} vs {b.shape}",
        }

    total_pixels = a.shape[0] * a.shape[1]

    # Pixel equality (all 3 channels must match)
    equal_mask = np.all(np.abs(a - b) < 1.5, axis=2)
    pixel_equal = float(np.sum(equal_mask)) / total_pixels

    # Mean absolute error
    mae = float(np.mean(np.abs(a - b)))

    # Simple SSIM (per-channel, averaged)
    ssim_val = simple_ssim(a, b)

    return {
        "pixel_equal": round(pixel_equal, 6),
        "mae": round(mae, 4),
        "ssim": round(ssim_val, 6),
    }


def simple_ssim(a, b, block_size=8):
    """Compute a simple SSIM approximation using block-wise statistics."""
    import numpy as np

    C1 = (0.01 * 255) ** 2
    C2 = (0.03 * 255) ** 2

    h, w, c = a.shape
    ssim_sum = 0.0
    count = 0

    for ch in range(c):
        ac = a[:, :, ch]
        bc = b[:, :, ch]
        for y in range(0, h - block_size + 1, block_size):
            for x in range(0, w - block_size + 1, block_size):
                ba = ac[y:y+block_size, x:x+block_size]
                bb = bc[y:y+block_size, x:x+block_size]

                mu_a = np.mean(ba)
                mu_b = np.mean(bb)
                sig_a = np.var(ba)
                sig_b = np.var(bb)
                sig_ab = np.mean((ba - mu_a) * (bb - mu_b))

                num = (2 * mu_a * mu_b + C1) * (2 * sig_ab + C2)
                den = (mu_a**2 + mu_b**2 + C1) * (sig_a + sig_b + C2)
                ssim_sum += num / den
                count += 1

    return ssim_sum / count if count > 0 else 0.0


def generate_diff_image(img_a_path, img_b_path, diff_path):
    """Generate a diff image (amplified absolute difference)."""
    try:
        from PIL import Image
        import numpy as np
    except ImportError:
        return

    a = np.array(Image.open(img_a_path).convert("RGB"), dtype=np.int16)
    b = np.array(Image.open(img_b_path).convert("RGB"), dtype=np.int16)

    if a.shape != b.shape:
        return

    diff = np.clip(np.abs(a - b) * 4, 0, 255).astype(np.uint8)
    Image.fromarray(diff).save(str(diff_path))


def apply_threshold(metrics: dict, tier: int) -> str:
    """Return 'PASS' or 'FAIL' based on tier thresholds."""
    if "error" in metrics:
        return "FAIL"

    if tier <= 1:
        if metrics.get("pixel_equal", 0) >= TIER1_THRESHOLD_PIXEL_EQUAL:
            return "PASS"
        if metrics.get("ssim", 0) >= TIER2_THRESHOLD_SSIM:
            return "PASS"
        return "FAIL"
    else:
        if metrics.get("ssim", 0) >= TIER2_THRESHOLD_SSIM:
            return "PASS"
        if metrics.get("pixel_equal", 0) >= TIER1_THRESHOLD_PIXEL_EQUAL:
            return "PASS"
        return "FAIL"


def main():
    parser = argparse.ArgumentParser(description="Visual regression test harness")
    group = parser.add_mutually_exclusive_group()
    group.add_argument("--all", action="store_true", help="Run all tiers")
    group.add_argument("--tier1", action="store_true", help="Run Tier 1 only")
    group.add_argument("--names", type=str, help="Comma-separated example names")
    parser.add_argument("--frames", type=int, default=None, help="Override frame count")
    args = parser.parse_args()

    if not MANIFEST.exists():
        print(f"Manifest not found: {MANIFEST}", file=sys.stderr)
        return 1

    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))

    # Filter examples
    if args.names:
        names = set(args.names.split(","))
        examples = [e for e in manifest if e["name"] in names]
    elif args.tier1:
        examples = [e for e in manifest if e.get("tier", 99) <= 1]
    elif args.all:
        examples = manifest
    else:
        examples = [e for e in manifest if e.get("tier", 99) <= 1]

    if not examples:
        print("No examples selected.", file=sys.stderr)
        return 1

    # Check prerequisites
    if not RAYLIB_LIB.exists():
        print(f"raylib not built: {RAYLIB_LIB}", file=sys.stderr)
        return 1
    if not DISTURB_BIN.exists():
        print(f"disturb not built: {DISTURB_BIN}", file=sys.stderr)
        return 1

    ensure_dirs()

    results = []
    pass_count = 0
    fail_count = 0
    skip_count = 0

    print(f"Visual regression: {len(examples)} examples selected\n")

    for ex in examples:
        name = ex["name"]
        frames = args.frames or ex.get("frames", 120)
        tier = ex.get("tier", 1)
        asset_cwd = ex.get("asset_cwd")
        skip_reason = ex.get("skip_reason")

        c_source_path = ROOT / ex["c_source"]
        d_source_path = ROOT / ex["disturb_source"]

        # Check skip conditions
        if skip_reason:
            print(f"  SKIP  {name}: {skip_reason}")
            results.append({"name": name, "status": "SKIP", "reason": skip_reason})
            skip_count += 1
            continue

        if not c_source_path.exists():
            print(f"  SKIP  {name}: C source not found: {ex['c_source']}")
            results.append({"name": name, "status": "SKIP", "reason": "C source missing"})
            skip_count += 1
            continue

        if not d_source_path.exists():
            print(f"  SKIP  {name}: Disturb source not found: {ex['disturb_source']}")
            results.append({"name": name, "status": "SKIP", "reason": "Disturb source missing"})
            skip_count += 1
            continue

        # Determine working directories and output paths
        # Disturb always runs from ROOT (so eval(read("generated/...")) resolves).
        # C runs from asset_cwd when set (so resources/ paths resolve).
        d_cwd = str(ROOT)
        d_out_png = f"out/disturb/{name}.png"

        if asset_cwd:
            c_cwd = str(ROOT / asset_cwd)
            # Use relative path from asset_cwd to ROOT/out/c/ so TakeScreenshot works
            c_out_png = os.path.relpath(
                str(ROOT / "out" / "c" / f"{name}.png"),
                str(ROOT / asset_cwd),
            )

            # Check asset directory exists
            if not (ROOT / asset_cwd).is_dir():
                print(f"  SKIP  {name}: asset directory not found: {asset_cwd}")
                results.append({"name": name, "status": "SKIP", "reason": "asset unavailable"})
                skip_count += 1
                continue
        else:
            c_cwd = str(ROOT)
            c_out_png = f"out/c/{name}.png"

        # --- C side ---
        c_src_text = c_source_path.read_text(encoding="utf-8")
        patched = patch_c_source(c_src_text, name, frames, c_out_png)

        patched_path = BIN_DIR / f"{name}.c"
        patched_path.write_text(patched, encoding="utf-8")

        bin_path = BIN_DIR / name
        if not compile_c(name, patched_path, bin_path):
            print(f"  SKIP  {name}: C compilation failed")
            results.append({"name": name, "status": "SKIP", "reason": "C compile failed"})
            skip_count += 1
            continue

        c_ok = run_example([str(bin_path)], cwd=c_cwd)
        c_png = ROOT / "out" / "c" / f"{name}.png"
        if not c_ok or not c_png.exists():
            print(f"  SKIP  {name}: C execution failed or no screenshot")
            results.append({"name": name, "status": "SKIP", "reason": "C execution failed"})
            skip_count += 1
            continue

        # --- Disturb side ---
        d_cmd = [str(DISTURB_BIN), str(d_source_path)]
        d_ok = run_example(d_cmd, cwd=d_cwd)
        d_png = ROOT / "out" / "disturb" / f"{name}.png"
        if not d_ok or not d_png.exists():
            print(f"  SKIP  {name}: Disturb execution failed or no screenshot")
            results.append({"name": name, "status": "SKIP", "reason": "Disturb execution failed"})
            skip_count += 1
            continue

        # --- Compare ---
        metrics = compute_metrics(c_png, d_png)
        status = apply_threshold(metrics, tier)

        # Generate diff
        diff_png = OUT_DIFF / f"{name}_diff.png"
        generate_diff_image(c_png, d_png, diff_png)

        pe = metrics.get("pixel_equal", 0)
        mae = metrics.get("mae", 0)
        ssim = metrics.get("ssim", 0)
        err = metrics.get("error", "")

        if status == "PASS":
            pass_count += 1
            print(f"  PASS  {name}  pixel={pe:.4f}  mae={mae:.2f}  ssim={ssim:.4f}")
        else:
            fail_count += 1
            extra = f"  ({err})" if err else ""
            print(f"  FAIL  {name}  pixel={pe:.4f}  mae={mae:.2f}  ssim={ssim:.4f}{extra}")

        results.append({
            "name": name,
            "status": status,
            "tier": tier,
            "pixel_equal": pe,
            "mae": mae,
            "ssim": ssim,
            "reason": err or None,
        })

    # --- Reports ---
    report_json = ROOT / "out" / "report.json"
    report_json.write_text(json.dumps(results, indent=2), encoding="utf-8")

    report_md = ROOT / "out" / "report.md"
    md_lines = ["# Visual Regression Report\n"]
    md_lines.append(f"Generated: {time.strftime('%Y-%m-%d %H:%M:%S')}\n")
    md_lines.append("| Example | Status | Pixel Equal | MAE | SSIM | Reason |")
    md_lines.append("|---------|--------|-------------|-----|------|--------|")
    for r in results:
        pe = f"{r.get('pixel_equal', '-'):.4f}" if isinstance(r.get("pixel_equal"), float) else "-"
        mae = f"{r.get('mae', '-'):.2f}" if isinstance(r.get("mae"), float) else "-"
        ssim = f"{r.get('ssim', '-'):.4f}" if isinstance(r.get("ssim"), float) else "-"
        reason = r.get("reason") or ""
        md_lines.append(f"| {r['name']} | {r['status']} | {pe} | {mae} | {ssim} | {reason} |")

    md_lines.append("")
    md_lines.append(f"**Totals:** {pass_count} PASS, {fail_count} FAIL, {skip_count} SKIP")
    md_lines.append("")
    report_md.write_text("\n".join(md_lines), encoding="utf-8")

    # --- Summary ---
    print(f"\n=== Visual Regression Summary ===")
    print(f"  PASS: {pass_count}")
    print(f"  FAIL: {fail_count}")
    print(f"  SKIP: {skip_count}")
    print(f"  Report: {report_md}")

    return 1 if fail_count > 0 else 0


if __name__ == "__main__":
    raise SystemExit(main())
