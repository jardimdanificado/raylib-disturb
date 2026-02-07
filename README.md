# raylib-disturb

Raylib bindings for the [Disturb](https://github.com/jardimdanificado/disturb) language via FFI.

## Prerequisites

- GCC or Clang
- GNU Make
- libffi development headers (`libffi-dev` / `libffi-devel`)
- X11 development headers (`libx11-dev` / `libX11-devel`)

On Debian/Ubuntu:

```
sudo apt install build-essential libffi-dev libx11-dev
```

On Arch:

```
sudo pacman -S base-devel libffi libx11
```

## Build

```
make
```

This builds:

1. **raylib** as a static library (`raylib/src/libraylib.a`)
2. **libraylib_disturb.so** - the C shim shared library in the project root
3. **disturb** interpreter with FFI enabled (`disturb/disturb`)

## Run examples

```
make run_hello      # Opens a window with text, shapes, and FPS counter
make run_texture    # Loads and draws assets/test.png
```

For the texture example, place any PNG file at `assets/test.png` before running.

## Project layout

```
shim/                     C shim source (flat C ABI over raylib)
disturb_bindings/         Disturb wrapper module
examples/                 Disturb example programs
assets/                   Texture/image assets
raylib/                   Vendored raylib source
disturb/                  Vendored Disturb source
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
