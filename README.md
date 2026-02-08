# raylib-disturb

Disturb bindings for raylib with a generated C shim + FFI layer and a user-facing Disturb API module.

## Overview
- Public module: `disturb_bindings/raylib.dist`
- Generated low-level FFI: `generated/raylib_ffi_phase3.dist`
- Generated C shim: `generated/raylib_shim_phase3.{h,c}` -> `libraylib_disturb_phase3.so`
- Portability ceiling: `SUPPORTED=587`, `NEEDS_MANUAL=0`, `OMITTED=12`
- Design constraints: no callbacks, no varargs, only `i32/f32/char*/void*` across FFI

## Compatibility
- raylib tested: `5.6-dev` (`raylib` commit `a6fa8b9`)
- Disturb tested: `0.18.0` (`disturb` commit `98c6960`)

## Prerequisites
- GCC or Clang
- GNU Make
- CMake (recommended)
- libffi development headers (`libffi-dev` / `libffi-devel`)
- X11 development headers (`libx11-dev` / `libX11-devel`)

## Build and Generate
```bash
make raylib_phase2
make raylib_phase3
make shim_phase3
```

This produces:
- `generated/plan.json`
- `generated/raylib_shim_phase3.h`
- `generated/raylib_shim_phase3.c`
- `generated/raylib_ffi_phase3.dist`
- `libraylib_disturb_phase3.so`
- `disturb_bindings/shim_path_phase3.bin`

Disturb loads the shared object via `generated/raylib_ffi_phase3.dist`.

## Public API Module
Use only:
```disturb
eval(read("disturb_bindings/raylib.dist"));
```

The module wraps low-level FFI and exposes ergonomic functions and handle objects.

## Quick Start
### Minimal window
```disturb
eval(read("disturb_bindings/raylib.dist"));

if (hasDisplay() == 0) {
  println("headless: skipping window");
}
else {
  initWindow(640, 360, "hello");
  setTargetFPS(60);

  frame = 0;
  while (windowShouldClose() == 0 && frame < 120) {
    frame = frame + 1;
    beginDrawing();
    clearBackground(COLOR_RAYWHITE);
    drawText("Hello raylib.dist", 180, 160, 24, COLOR_DARKGRAY);
    endDrawing();
  }

  closeWindow();
}
```

### Minimal headless/offscreen
```disturb
eval(read("disturb_bindings/raylib.dist"));

img = beginOffscreen(32, 24, COLOR_BLACK);
img.drawRectangle(4, 4, 10, 8, COLOR_GREEN);

if (assertPixelEquals(img, 6, 6, COLOR_GREEN) == 1) {
  println("PASS offscreen");
}
else {
  println("FAIL offscreen");
}

img.unload();
```

## API Overview
### Core
- `initWindow(w, h, title)`
- `closeWindow()`
- `windowShouldClose()`
- `setTargetFPS(fps)`
- `getFPS()`, `getFrameTime()`, `getTime()`, `waitTime(sec)`

### Drawing
- `beginDrawing()`, `endDrawing()`
- `clearBackground(color)`
- `drawText(text, x, y, size, color)`
- `drawRectangle(x, y, w, h, color)`
- `drawRectangleLines(x, y, w, h, color)`
- `drawCircle(x, y, radius, color)`
- `drawLine(x1, y1, x2, y2, color)`
- `drawFPS(x, y)`

### Input
- `isKeyDown(key)`, `isKeyPressed(key)`, `getKeyPressed()`
- `getMousePosition()` -> `{x, y, ok}`
- `getMouseWheelMove()`

### Text
- `measureText(text, size)`

### Texture handles
- `tex = loadTexture(path)`
- `tex.draw(x, y, tint)`
- `tex.drawEx(x, y, rotation, scale, tint)`
- `tex.drawRec(sx, sy, sw, sh, dx, dy, tint)`
- `tex.unload()`

### Camera2D
- `beginMode2D(camera)`
- `endMode2D()`
- `getCameraMatrix2D(camera)` -> `{ok, m0..m15}`
- Note: current ergonomic layer uses null/opaque camera handles; full constructor wrappers are future work.

### Audio
- low-level APIs are available through generated FFI
- on headless/CI systems audio device initialization may fail and should be treated as skip

## Pointer and Memory Model
- `void*` handles are 64-bit safe.
- Disturb FFI now roundtrips pointer values through integer storage without truncation.
- Validation test: `examples_phase3/test_ptr_roundtrip.dist`.
- Ownership rules:
  - textures: call `tex.unload()`
  - images/offscreen: call `img.unload()`
  - other native handles should be explicitly unloaded/freed by the matching API
- Do not rely on GC for native resource release.

## Known Limitations
These 12 APIs are intentionally omitted (callbacks/varargs):
- `AttachAudioMixedProcessor` (callback)
- `AttachAudioStreamProcessor` (callback)
- `DetachAudioMixedProcessor` (callback)
- `DetachAudioStreamProcessor` (callback)
- `SetAudioStreamCallback` (callback)
- `SetLoadFileDataCallback` (callback)
- `SetLoadFileTextCallback` (callback)
- `SetSaveFileDataCallback` (callback)
- `SetSaveFileTextCallback` (callback)
- `SetTraceLogCallback` (callback)
- `TextFormat` (varargs)
- `TraceLog` (varargs)

Suggested alternatives:
- implement logging/formatting on Disturb side
- use polling/state APIs instead of callback registration

## Examples
### Regression suites
- `examples_phase3/` for smoke + conformance
- `examples_raylib_port/` for official example ports

### User-facing examples
- `examples_user/hello_window.dist`
- `examples_user/basic_shapes.dist`
- `examples_user/texture_draw.dist`
- `examples_user/text_render.dist`
- `examples_user/camera2d.dist`
- `examples_user/headless_offscreen.dist`

Run them with:
```bash
make run_examples_user
```

## Validation Commands
All should pass before release:
```bash
make raylib_phase2
make raylib_phase3
make shim_phase3
make verify_phase3_symbols
make run_phase3_smoke
make run_phase6_conformance
make run_ported_examples
make run_examples_user
```

## Testing
One-command local workflows:
```bash
make test_all
make test_headless
make test_windowed   # Linux only, requires xvfb-run
```

Ported examples quality-of-life:
```bash
make run_ported_examples_list
make run_ported_examples_fast
make run_ported_examples
```

Ported examples are defined in `examples_raylib_port/manifest.json` and runner files are generated from it.
Suite summary includes:
- `PASS_TOTAL`
- `PASS_HEADLESS`
- `PASS_WINDOWED`
- `SKIP`
- `FAIL`

The runner exits non-zero when any `FAIL` occurs.

To reduce SKIPs for asset-dependent examples, add:
- `assets/test.png`
- `assets/font.ttf`
- `assets/model.obj`
- `assets/test.wav`
- `assets/test.ogg`

## CI Notes
- Linux headless CI runs `make -s test_headless`.
- Linux windowed CI runs `make -s test_windowed` under Xvfb (`1280x720x24`).
- macOS CI prefers `make -s test_headless` and falls back to a build+core-test subset if needed.
- Windows CI runs a headless-like subset (build, symbol verification, smoke, conformance); windowed suites are intentionally skipped.
- ALSA warnings can appear in CI logs when no audio device is available; examples should SKIP gracefully.
