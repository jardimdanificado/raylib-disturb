CC       ?= gcc
CFLAGS   := -O2 -Wall -Wextra -fPIC
LDFLAGS  :=
CMAKE    ?= cmake

RAYLIB_SRC     := raylib
RAYLIB_BUILD   := $(RAYLIB_SRC)/build
RAYLIB_LIB     := $(RAYLIB_BUILD)/raylib/libraylib.a

SHIM_SRC       := shim/raylib_disturb.c
SHIM_HDR       := shim/raylib_disturb.h
SHIM_SO        := libraylib_disturb.so
SHIM_PATH_BIN  := disturb_bindings/shim_path.bin

DISTURB_DIR    := disturb
DISTURB_BIN    := $(DISTURB_DIR)/disturb

# System libs needed by raylib on Linux (X11 desktop)
RAYLIB_SYSLIBS := -lm -lpthread -ldl -lrt -lX11

.PHONY: all raylib shim disturb clean run_smoke run_hello run_texture run_texture_stress

all: raylib shim disturb $(SHIM_PATH_BIN)

# ---------- raylib (static, built with CMake) ----------
raylib: $(RAYLIB_LIB)

$(RAYLIB_LIB):
	@if command -v $(CMAKE) >/dev/null 2>&1; then \
		$(CMAKE) -S $(RAYLIB_SRC) -B $(RAYLIB_BUILD) \
			-DBUILD_SHARED_LIBS=OFF \
			-DBUILD_EXAMPLES=OFF \
			-DCMAKE_POSITION_INDEPENDENT_CODE=ON; \
		$(CMAKE) --build $(RAYLIB_BUILD) -j; \
	else \
		echo "cmake not found; falling back to raylib/src Makefile build"; \
		$(MAKE) -C $(RAYLIB_SRC)/src \
			PLATFORM=PLATFORM_DESKTOP \
			RAYLIB_LIBTYPE=STATIC \
			CUSTOM_CFLAGS="-fPIC"; \
		mkdir -p $(RAYLIB_BUILD)/raylib; \
		cp $(RAYLIB_SRC)/src/libraylib.a $(RAYLIB_LIB); \
	fi

# ---------- shim shared library ----------
shim: $(SHIM_SO)

$(SHIM_SO): $(SHIM_SRC) $(SHIM_HDR) $(RAYLIB_LIB)
	$(CC) $(CFLAGS) -shared \
		-I$(RAYLIB_SRC)/src -Ishim \
		$(SHIM_SRC) \
		$(RAYLIB_LIB) \
		$(RAYLIB_SYSLIBS) \
		-o $(SHIM_SO)

$(SHIM_PATH_BIN):
	printf './libraylib_disturb.so\0' > $(SHIM_PATH_BIN)

# ---------- disturb interpreter ----------
disturb: $(DISTURB_BIN)

$(DISTURB_BIN):
	$(MAKE) -C $(DISTURB_DIR) ENABLE_FFI=1

# ---------- run examples ----------
run_smoke: all
	./$(DISTURB_BIN) examples/smoke_load.dist

run_hello: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/hello_window.dist

run_texture: all
	./$(DISTURB_BIN) examples/texture.disturb

run_texture_stress: all
	./$(DISTURB_BIN) examples/texture_stress.dist

# ---------- clean ----------
clean:
	rm -rf $(RAYLIB_BUILD)
	rm -f $(SHIM_SO)
	rm -f $(SHIM_PATH_BIN)
	$(MAKE) -C $(DISTURB_DIR) clean
