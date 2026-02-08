# raylib-disturb

Raylib bindings for the [Disturb](https://github.com/jardimdanificado/disturb) language via FFI.

## Prerequisites

- GCC or Clang
- GNU Make
- CMake (recommended; Makefile fallback is used if unavailable)
- libffi development headers (`libffi-dev` / `libffi-devel`)
- X11 development headers (`libx11-dev` / `libX11-devel`)

On Debian/Ubuntu:

```
sudo apt install build-essential cmake libffi-dev libx11-dev
```

On Arch:

```
sudo pacman -S base-devel cmake libffi libx11
```

## Build

```
make
```

This builds:

1. **raylib** as a static library (`raylib/build/raylib/libraylib.a`)
2. **libraylib_disturb.so** - the C shim shared library in the project root
3. **disturb** interpreter with FFI enabled (`disturb/disturb`)
4. **disturb_bindings/shim_path.bin** generated helper file (null-terminated `./libraylib_disturb.so` path for `ffi.load`)

## Run examples

```
make run_smoke          # No-window FFI load smoke test
make run_hello          # Minimal hello window run
make run_texture        # Loads and draws assets/test.png
make run_texture_stress # Repeated load/draw/unload texture test
make run_texture_pro    # DrawTexturePro-style rotate/scale/pivot demo
make run_procedural     # Create/update texture from int[] RGBA8 pixels
make run_measure_text   # measureText visual check
make run_camera2d       # Camera2D pan/zoom demo
make run_quick_tests    # Headless quick checks (packing/pixels)
make run_new_examples   # Quick test + procedural + measureText
```

`make run_hello` sets `DISTURB_HEADLESS=1` to keep CI/headless environments deterministic.
Run `./disturb/disturb examples/hello_window.disturb` directly for the interactive window loop.

Texture-based examples require `assets/test.png`.
Place any small PNG at that path:

```bash
cp /path/to/your/image.png assets/test.png
```

`make run_texture_stress` exits gracefully with instructions if `assets/test.png` is missing.

Optional font demo asset:

```bash
cp /path/to/your/font.ttf assets/font.ttf
```

Then run:

```bash
./disturb/disturb examples/font_ex.disturb
```

## Helper tooling

```bash
tools/check_symbols.sh
```

Prints exported `rl_*` symbols from `./libraylib_disturb.so` using `nm -D` (or `objdump -T` fallback).

## Project layout

```
shim/                     C shim source (flat C ABI over raylib)
disturb_bindings/         Disturb wrapper module
examples/                 Disturb example programs
assets/                   Texture/image assets
raylib/                   Vendored raylib source
disturb/                  Vendored Disturb source
tools/                    Small project helper scripts
libraylib_disturb.so      Built shim library (after make)
```

## Usage in your own scripts

```
eval(read("disturb_bindings/raylib.disturb"));

initWindow(800, 450, "My App");
setTargetFPS(60);

while (shouldClose() == 0) {
  begin();
  clear(COLOR_RAYWHITE);
  drawText("Hello!", 100, 100, 30, COLOR_DARKGRAY);
  end();
}

closeWindow();
```

The bindings load `./libraylib_disturb.so` from the current directory. Run scripts from the project root so the path resolves correctly.

## Extended API

### Sprite transforms (DrawTexturePro)

```
tex = loadTexture("sprite.png");
// drawPro(srcX,srcY,srcW,srcH, dstX,dstY,dstW,dstH, originX,originY, rotation, tint)
tex.drawPro(0,0,32,32, 100,100,64,64, 32,32, 45.0, COLOR_WHITE);
```

### Procedural textures

```
pixels = [];  // int[] of packed 0xRRGGBBAA
for (i = 0; i < 64*64; i = i + 1) { pixels.push(rgba(i % 256, 0, 128, 255)); }
tex = makeTexture(64, 64, pixels);
// Update later:
tex.updatePixels(new_pixels);
tex.free();
```

### Text measurement and custom fonts

```
w = measureText("Hello", 20);               // default font
font = loadFont("assets/myfont.ttf");
font.draw("Custom text", 10, 10, 24, 1.0, COLOR_WHITE);
w2 = font.measure("Custom text", 24, 1.0);
font.free();
```

### 2D camera

```
cam = createCamera2D(400, 300, 0, 0, 0.0, 1.0);
// In draw loop:
cam.begin();
  drawRect(-50, -50, 100, 100, COLOR_RED);   // world-space drawing
cam.end();
cam.set(400, 300, player_x, player_y, 0.0, 2.0);  // update each frame
cam.free();
```
