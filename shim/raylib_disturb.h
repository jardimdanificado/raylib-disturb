#ifndef RAYLIB_DISTURB_H
#define RAYLIB_DISTURB_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Window / timing */
int   rl_init_window(int w, int h, const char *title);
int   rl_init_window_n(int w, int h, const char *title, int title_len);
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
void  rl_draw_text_n(const char *text, int text_len,
                     int x, int y, int size, int rgba);

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

/* A) 2D sprite transforms (DrawTexturePro) */
void     rl_draw_texture_pro(intptr_t tex,
                             float sx, float sy, float sw, float sh,
                             float dx, float dy, float dw, float dh,
                             float ox, float oy,
                             float rot_deg, int rgba_tint);

/* B) Procedural textures: create from pixels, update pixels */
intptr_t rl_make_texture_rgba8(int w, int h, intptr_t pixels, int pixel_count);
void     rl_update_texture_rgba8(intptr_t tex, intptr_t pixels, int pixel_count);

/* C) Text measurement + custom fonts */
int      rl_measure_text(const char *text, int font_size);
int      rl_measure_text_n(const char *text, int text_len, int font_size);
intptr_t rl_load_font(const char *path);
intptr_t rl_load_font_n(const char *path, int path_len);
void     rl_unload_font(intptr_t font);
int      rl_measure_text_ex(intptr_t font, const char *text,
                            float font_size, float spacing);
int      rl_measure_text_ex_n(intptr_t font, const char *text, int text_len,
                              float font_size, float spacing);
void     rl_draw_text_ex(intptr_t font, const char *text,
                         float x, float y, float font_size,
                         float spacing, int rgba);
void     rl_draw_text_ex_n(intptr_t font, const char *text, int text_len,
                           float x, float y, float font_size,
                           float spacing, int rgba);

/* D) 2D camera */
intptr_t rl_camera2d_create(float offset_x, float offset_y,
                            float target_x, float target_y,
                            float rotation, float zoom);
void     rl_camera2d_set(intptr_t cam,
                         float offset_x, float offset_y,
                         float target_x, float target_y,
                         float rotation, float zoom);
void     rl_camera2d_begin(intptr_t cam);
void     rl_camera2d_end(void);
void     rl_camera2d_destroy(intptr_t cam);

#ifdef __cplusplus
}
#endif

#endif /* RAYLIB_DISTURB_H */
