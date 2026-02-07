CC       ?= gcc
CFLAGS   := -O2 -Wall -Wextra -fPIC
LDFLAGS  :=
CMAKE    ?= cmake
CLONE_DEPTH ?= 1

RAYLIB_SRC     := raylib
RAYLIB_REPO    ?= https://github.com/raysan5/raylib.git
RAYLIB_BUILD   := $(RAYLIB_SRC)/build
RAYLIB_LIB     := $(RAYLIB_BUILD)/raylib/libraylib.a

SHIM_SRC       := shim/raylib_disturb.c
SHIM_HDR       := shim/raylib_disturb.h
SHIM_SO        := libraylib_disturb.so
SHIM_PATH_BIN  := disturb_bindings/shim_path.bin

DISTURB_DIR    := disturb
DISTURB_REPO   ?= https://github.com/jardimdanificado/disturb.git
DISTURB_BIN    := $(DISTURB_DIR)/disturb

# System libs needed by raylib on Linux (X11 desktop)
RAYLIB_SYSLIBS := -lm -lpthread -ldl -lrt -lX11

.PHONY: all deps clone raylib_repo disturb_repo raylib shim disturb clean run_smoke run_hello run_texture run_texture_stress

all: deps raylib shim disturb $(SHIM_PATH_BIN)

clone: deps

deps: raylib_repo disturb_repo

raylib_repo:
	@if [ ! -d "$(RAYLIB_SRC)" ]; then \
		git clone --depth "$(CLONE_DEPTH)" "$(RAYLIB_REPO)" "$(RAYLIB_SRC)"; \
	elif [ -d "$(RAYLIB_SRC)/.git" ]; then \
		echo "$(RAYLIB_SRC) already present"; \
	else \
		echo "$(RAYLIB_SRC) exists but is not a git clone; skipping clone"; \
	fi

disturb_repo:
	@if [ ! -d "$(DISTURB_DIR)" ]; then \
		git clone --depth "$(CLONE_DEPTH)" "$(DISTURB_REPO)" "$(DISTURB_DIR)"; \
	elif [ -d "$(DISTURB_DIR)/.git" ]; then \
		echo "$(DISTURB_DIR) already present"; \
	else \
		echo "$(DISTURB_DIR) exists but is not a git clone; skipping clone"; \
	fi

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
	./$(DISTURB_BIN) examples/smoke_load.disturb

run_hello: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/hello_window.disturb

run_texture: all
	./$(DISTURB_BIN) examples/texture.disturb

run_texture_stress: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/texture_stress.disturb

# ---------- clean ----------
clean:
	rm -rf $(RAYLIB_BUILD)
	rm -f $(SHIM_SO)
	rm -f $(SHIM_PATH_BIN)
	@if [ -d "$(RAYLIB_SRC)/src" ]; then $(MAKE) -C $(RAYLIB_SRC)/src clean; fi
	@if [ -d "$(DISTURB_DIR)" ]; then $(MAKE) -C $(DISTURB_DIR) clean; fi
	rm -rf $(RAYLIB_SRC)
	rm -rf $(DISTURB_DIR)
