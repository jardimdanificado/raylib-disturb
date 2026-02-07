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
```

`make run_hello` sets `DISTURB_HEADLESS=1` to keep CI/headless environments deterministic.
Run `./disturb/disturb examples/hello_window.dist` directly for the interactive window loop.

Texture-based examples require `assets/test.png`.
Place any small PNG at that path:

```bash
cp /path/to/your/image.png assets/test.png
```

`make run_texture_stress` exits gracefully with instructions if `assets/test.png` is missing.

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
