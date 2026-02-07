#ifndef RAYLIB_DISTURB_H
#define RAYLIB_DISTURB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Window / timing */
int   rl_init_window(int w, int h, const char *title);
int   rl_window_should_close(void);
void  rl_begin_drawing(void);
void  rl_end_drawing(void);
void  rl_close_window(void);
void  rl_set_target_fps(int fps);
int   rl_get_fps(void);

/* Drawing (packed RGBA as 0xRRGGBBAA) */
void  rl_clear_background(int rgba);
void  rl_draw_pixel(int x, int y, int rgba);
void  rl_draw_line(int x1, int y1, int x2, int y2, int rgba);
void  rl_draw_circle(int cx, int cy, float r, int rgba);
void  rl_draw_rectangle(int x, int y, int w, int h, int rgba);
void  rl_draw_text(const char *text, int x, int y, int size, int rgba);

/* Input (polling) */
int   rl_is_key_down(int key);
int   rl_is_key_pressed(int key);
int   rl_get_key_pressed(void);
int   rl_is_mouse_button_down(int button);
int   rl_is_mouse_button_pressed(int button);
float rl_get_mouse_x(void);
float rl_get_mouse_y(void);
float rl_get_mouse_wheel_move(void);

/* Texture handles (opaque pointers returned/accepted as intptr_t for FFI) */
intptr_t rl_load_texture(const char *path);
intptr_t rl_load_texture_n(const char *path, int path_len);
void     rl_unload_texture(intptr_t tex);
int      rl_texture_width(intptr_t tex);
int      rl_texture_height(intptr_t tex);
void     rl_draw_texture(intptr_t tex, int x, int y, int rgba_tint);
void     rl_draw_texture_ex(intptr_t tex, float x, float y,
                            float rot_deg, float scale, int rgba_tint);
void     rl_draw_texture_region(intptr_t tex,
                                float sx, float sy, float sw, float sh,
                                float dx, float dy, int rgba_tint);

#ifdef __cplusplus
}
#endif

#endif /* RAYLIB_DISTURB_H */
