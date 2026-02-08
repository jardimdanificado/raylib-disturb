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
SHIM3_SRC      := generated/raylib_shim_phase3.c
SHIM3_HDR      := generated/raylib_shim_phase3.h
SHIM3_SO       := libraylib_disturb_phase3.so
SHIM3_PATH_BIN := disturb_bindings/shim_path_phase3.bin
PORTED_MANIFEST := examples_raylib_port/manifest.json
PORTED_TOOL    := tools/ported_examples_tool.py
PORTED_RUN_ALL := examples_raylib_port/run_all.dist
PORTED_RUN_FAST := examples_raylib_port/run_fast.dist

DISTURB_DIR    := disturb
DISTURB_REPO   ?= https://github.com/jardimdanificado/disturb.git
DISTURB_BIN    := $(DISTURB_DIR)/disturb

# System libs needed by raylib on Linux (X11 desktop)
RAYLIB_SYSLIBS := -lm -lpthread -ldl -lrt -lX11

.PHONY: all deps clone raylib_repo disturb_repo raylib shim disturb clean deep_clean assets_note run_smoke run_hello run_texture run_texture_stress run_texture_pro run_procedural run_measure_text run_camera2d run_quick_tests run_new_examples run_core_basic_window run_core_input_keys run_textures_image_loading run_core_2d_camera run_original_examples raylib_inventory raylib_phase2 raylib_phase3 shim_phase3 run_phase3_smoke run_phase6_conformance verify_phase3_symbols sync_ported_examples run_ported_examples run_ported_examples_fast run_ported_examples_list run_examples_user test_headless test_windowed test_all clean_phase3 visual_regress_fast visual_regress_all visual_regress_clean

all: deps raylib shim disturb $(SHIM_PATH_BIN)

clone: deps

deps: raylib_repo disturb_repo

raylib_repo:
	@if [ ! -d "$(RAYLIB_SRC)" ]; then \
		git clone --depth "$(CLONE_DEPTH)" "$(RAYLIB_REPO)" "$(RAYLIB_SRC)"; \
	elif [ -d "$(RAYLIB_SRC)" ] && [ -z "$$(ls -A "$(RAYLIB_SRC)")" ]; then \
		rmdir "$(RAYLIB_SRC)"; \
		git clone --depth "$(CLONE_DEPTH)" "$(RAYLIB_REPO)" "$(RAYLIB_SRC)"; \
	elif [ -d "$(RAYLIB_SRC)/.git" ]; then \
		echo "$(RAYLIB_SRC) already present"; \
	else \
		echo "$(RAYLIB_SRC) exists but is not a git clone; skipping clone"; \
	fi

disturb_repo:
	@if [ ! -d "$(DISTURB_DIR)" ]; then \
		git clone --depth "$(CLONE_DEPTH)" "$(DISTURB_REPO)" "$(DISTURB_DIR)"; \
	elif [ -d "$(DISTURB_DIR)" ] && [ -z "$$(ls -A "$(DISTURB_DIR)")" ]; then \
		rmdir "$(DISTURB_DIR)"; \
		git clone --depth "$(CLONE_DEPTH)" "$(DISTURB_REPO)" "$(DISTURB_DIR)"; \
	elif [ -d "$(DISTURB_DIR)/.git" ]; then \
		echo "$(DISTURB_DIR) already present"; \
	else \
		echo "$(DISTURB_DIR) exists but is not a git clone; skipping clone"; \
	fi

# ---------- raylib (static, built with CMake) ----------
raylib: $(RAYLIB_LIB)

$(RAYLIB_LIB):
	@if [ ! -f "$(RAYLIB_SRC)/src/Makefile" ] && [ ! -f "$(RAYLIB_SRC)/CMakeLists.txt" ]; then \
		echo "raylib sources not found in $(RAYLIB_SRC). Run: make deps"; \
		exit 1; \
	fi
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
	@if [ ! -f "$(DISTURB_DIR)/Makefile" ]; then \
		echo "disturb sources not found in $(DISTURB_DIR). Run: make deps"; \
		exit 1; \
	fi
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

run_texture_pro: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/texture_pro.disturb

run_procedural: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/procedural_texture.disturb

run_measure_text: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/measure_text.disturb

run_camera2d: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/camera2d.disturb

run_quick_tests: all
	./$(DISTURB_BIN) examples/test_runner.disturb

run_new_examples: run_quick_tests run_procedural run_measure_text

run_core_basic_window: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/core_basic_window.disturb

run_core_input_keys: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/core_input_keys.disturb

run_textures_image_loading: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/textures_image_loading.disturb

run_core_2d_camera: all
	DISTURB_HEADLESS=1 ./$(DISTURB_BIN) examples/core_2d_camera.disturb

run_original_examples: run_core_basic_window run_core_input_keys run_textures_image_loading run_core_2d_camera

raylib_inventory: disturb
	mkdir -p generated
	python tools/raylib_gen.py

raylib_phase2: raylib_inventory
	mkdir -p generated
	python tools/raylib_phase2.py

raylib_phase3: raylib_phase2
	mkdir -p generated
	python tools/raylib_phase3.py

shim_phase3: raylib_phase3 raylib
	$(CC) $(CFLAGS) -shared \
		-I$(RAYLIB_SRC)/src -Igenerated \
		$(SHIM3_SRC) \
		$(RAYLIB_LIB) \
		$(RAYLIB_SYSLIBS) \
		-o $(SHIM3_SO)
	printf './libraylib_disturb_phase3.so\0' > $(SHIM3_PATH_BIN)

run_phase3_smoke: shim_phase3 disturb
	./$(DISTURB_BIN) examples_phase3/smoke_load.dist
	./$(DISTURB_BIN) examples_phase3/test_ptr_roundtrip.dist
	./$(DISTURB_BIN) examples_phase3/test_str_roundtrip.dist
	@out="$$(./$(DISTURB_BIN) examples_phase3/smoke_pure.dist 2>&1)"; \
	echo "$$out"; \
	if printf "%s\n" "$$out" | rg -q "(^FAIL |ffi\\.load failed|bytecode error|unknown native)"; then exit 1; fi
	./$(DISTURB_BIN) examples_phase3/smoke_core.dist
	./$(DISTURB_BIN) examples_phase3/smoke_draw.dist
	./$(DISTURB_BIN) examples_phase3/smoke_text.dist
	./$(DISTURB_BIN) examples_phase3/smoke_texture.dist
	./$(DISTURB_BIN) examples_phase3/smoke_audio.dist

run_phase6_conformance: shim_phase3 disturb
	./$(DISTURB_BIN) examples_phase3/conformance_phase6.dist

verify_phase3_symbols: shim_phase3
	python tools/verify_phase3_symbols.py

sync_ported_examples: $(PORTED_MANIFEST) $(PORTED_TOOL)
	python $(PORTED_TOOL) --generate

run_ported_examples: shim_phase3 disturb sync_ported_examples
	./$(DISTURB_BIN) $(PORTED_RUN_ALL)

run_ported_examples_fast: shim_phase3 disturb sync_ported_examples
	./$(DISTURB_BIN) $(PORTED_RUN_FAST)

run_ported_examples_list: $(PORTED_MANIFEST) $(PORTED_TOOL)
	python $(PORTED_TOOL) --list

run_examples_user: shim_phase3 disturb
	./$(DISTURB_BIN) examples_user/headless_offscreen.dist
	./$(DISTURB_BIN) examples_user/hello_window.dist
	./$(DISTURB_BIN) examples_user/basic_shapes.dist
	./$(DISTURB_BIN) examples_user/texture_draw.dist
	./$(DISTURB_BIN) examples_user/text_render.dist
	./$(DISTURB_BIN) examples_user/camera2d.dist

test_headless:
	$(MAKE) -s raylib_phase2
	$(MAKE) -s raylib_phase3
	$(MAKE) -s shim_phase3
	$(MAKE) -s verify_phase3_symbols
	$(MAKE) -s run_phase3_smoke
	$(MAKE) -s run_phase6_conformance
	$(MAKE) -s run_ported_examples

test_all:
	$(MAKE) -s test_headless
	$(MAKE) -s run_examples_user

test_windowed:
	@if [ "$$(uname -s)" != "Linux" ]; then \
		echo "test_windowed is Linux-only"; \
		exit 0; \
	fi
	@if ! command -v xvfb-run >/dev/null 2>&1; then \
		echo "xvfb-run not found. Install xvfb to run windowed tests."; \
		exit 1; \
	fi
	$(MAKE) -s test_headless
	xvfb-run -a -s "-screen 0 1280x720x24" $(MAKE) -s run_ported_examples run_examples_user

assets_note:
	@echo "Required: assets/test.png (for texture_pro/texture demos)"
	@echo "Optional: assets/font.ttf (for examples/font_ex.disturb)"

# ---------- clean ----------
clean:
	rm -rf $(RAYLIB_BUILD)
	rm -f $(SHIM_SO)
	rm -f $(SHIM_PATH_BIN)
	@if [ -d "$(RAYLIB_SRC)/src" ]; then $(MAKE) -C $(RAYLIB_SRC)/src clean; fi
	@if [ -d "$(DISTURB_DIR)" ]; then $(MAKE) -C $(DISTURB_DIR) clean; fi

deep_clean: clean
	rm -rf $(RAYLIB_SRC)
	rm -rf $(DISTURB_DIR)

clean_phase3:
	rm -f $(SHIM3_SO)
	rm -f $(SHIM3_PATH_BIN)
	rm -f generated/raylib_shim_phase3.h
	rm -f generated/raylib_shim_phase3.c
	rm -f generated/raylib_ffi_phase3.dist

visual_regress_fast: shim_phase3 disturb
	python tools/visual_regress.py --tier1

visual_regress_all: shim_phase3 disturb
	python tools/visual_regress.py --all

visual_regress_clean:
	rm -rf out/ bin/c_regress/
