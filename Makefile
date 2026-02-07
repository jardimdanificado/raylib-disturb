CC       ?= gcc
CFLAGS   := -O2 -Wall -Wextra -fPIC
LDFLAGS  :=

RAYLIB_SRC     := raylib
RAYLIB_LIB     := $(RAYLIB_SRC)/src/libraylib.a

SHIM_SRC       := shim/raylib_disturb.c
SHIM_HDR       := shim/raylib_disturb.h
SHIM_SO        := libraylib_disturb.so

DISTURB_DIR    := disturb
DISTURB_BIN    := $(DISTURB_DIR)/disturb

# System libs needed by raylib on Linux (X11 desktop)
RAYLIB_SYSLIBS := -lm -lpthread -ldl -lrt -lX11

.PHONY: all raylib shim disturb clean run_hello run_texture

all: raylib shim disturb

# ---------- raylib (static, built with its own Makefile) ----------
raylib: $(RAYLIB_LIB)

$(RAYLIB_LIB):
	$(MAKE) -C $(RAYLIB_SRC)/src \
		PLATFORM=PLATFORM_DESKTOP \
		RAYLIB_LIBTYPE=STATIC \
		CUSTOM_CFLAGS="-fPIC"

# ---------- shim shared library ----------
shim: $(SHIM_SO)

$(SHIM_SO): $(SHIM_SRC) $(SHIM_HDR) $(RAYLIB_LIB)
	$(CC) $(CFLAGS) -shared \
		-I$(RAYLIB_SRC)/src -Ishim \
		$(SHIM_SRC) \
		$(RAYLIB_LIB) \
		$(RAYLIB_SYSLIBS) \
		-o $(SHIM_SO)

# ---------- disturb interpreter ----------
disturb: $(DISTURB_BIN)

$(DISTURB_BIN):
	$(MAKE) -C $(DISTURB_DIR) ENABLE_FFI=1

# ---------- run examples ----------
run_hello: all
	./$(DISTURB_BIN) examples/hello_window.disturb

run_texture: all
	./$(DISTURB_BIN) examples/texture.disturb

# ---------- clean ----------
clean:
	$(MAKE) -C $(RAYLIB_SRC)/src clean
	rm -f $(SHIM_SO)
	$(MAKE) -C $(DISTURB_DIR) clean
