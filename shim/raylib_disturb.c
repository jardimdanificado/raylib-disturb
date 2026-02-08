#include "raylib_disturb.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* ---- helper: packed 0xRRGGBBAA -> raylib Color ---- */
static Color rgba_to_color(int rgba)
{
    unsigned int u = (unsigned int)rgba;
    Color c;
    c.r = (unsigned char)((u >> 24) & 0xFF);
    c.g = (unsigned char)((u >> 16) & 0xFF);
    c.b = (unsigned char)((u >>  8) & 0xFF);
    c.a = (unsigned char)( u        & 0xFF);
    return c;
}

/* ---- helper: cast intptr_t handle back to Texture2D* ---- */
static Texture2D *tex_ptr(intptr_t handle)
{
    return (Texture2D *)(void *)handle;
}

/* Disturb strings are not guaranteed to be NUL-terminated. */
static char *copy_string_n(const char *s, int len)
{
    if (!s || len < 0) return NULL;
    char *out = (char *)malloc((size_t)len + 1);
    if (!out) return NULL;
    for (int i = 0; i < len; i++) out[i] = s[i];
    out[len] = '\0';
    return out;
}

/* ================================================================
   Window / timing
   ================================================================ */

int rl_init_window(int w, int h, const char *title)
{
    InitWindow(w, h, title);
    return 1;
}

int rl_init_window_n(int w, int h, const char *title, int title_len)
{
    char *safe_title = copy_string_n(title, title_len);
    if (!safe_title) return 0;
    InitWindow(w, h, safe_title);
    free(safe_title);
    return 1;
}

int rl_window_should_close(void)
{
    return WindowShouldClose() ? 1 : 0;
}

void rl_begin_drawing(void)
{
    BeginDrawing();
}

void rl_end_drawing(void)
{
    EndDrawing();
}

void rl_close_window(void)
{
    CloseWindow();
}

void rl_set_target_fps(int fps)
{
    SetTargetFPS(fps);
}

int rl_get_fps(void)
{
    return GetFPS();
}

/* ================================================================
   Drawing
   ================================================================ */

void rl_clear_background(int rgba)
{
    ClearBackground(rgba_to_color(rgba));
}

void rl_draw_pixel(int x, int y, int rgba)
{
    DrawPixel(x, y, rgba_to_color(rgba));
}

void rl_draw_line(int x1, int y1, int x2, int y2, int rgba)
{
    DrawLine(x1, y1, x2, y2, rgba_to_color(rgba));
}

void rl_draw_circle(int cx, int cy, float r, int rgba)
{
    DrawCircle(cx, cy, r, rgba_to_color(rgba));
}

void rl_draw_rectangle(int x, int y, int w, int h, int rgba)
{
    DrawRectangle(x, y, w, h, rgba_to_color(rgba));
}

void rl_draw_text(const char *text, int x, int y, int size, int rgba)
{
    DrawText(text, x, y, size, rgba_to_color(rgba));
}

void rl_draw_text_n(const char *text, int text_len,
                    int x, int y, int size, int rgba)
{
    char *safe_text = copy_string_n(text, text_len);
    if (!safe_text) return;
    DrawText(safe_text, x, y, size, rgba_to_color(rgba));
    free(safe_text);
}

/* ================================================================
   Input (polling)
   ================================================================ */

int rl_is_key_down(int key)
{
    return IsKeyDown(key) ? 1 : 0;
}

int rl_is_key_pressed(int key)
{
    return IsKeyPressed(key) ? 1 : 0;
}

int rl_get_key_pressed(void)
{
    return GetKeyPressed();
}

int rl_is_mouse_button_down(int button)
{
    return IsMouseButtonDown(button) ? 1 : 0;
}

int rl_is_mouse_button_pressed(int button)
{
    return IsMouseButtonPressed(button) ? 1 : 0;
}

float rl_get_mouse_x(void)
{
    return GetMousePosition().x;
}

float rl_get_mouse_y(void)
{
    return GetMousePosition().y;
}

float rl_get_mouse_wheel_move(void)
{
    return GetMouseWheelMove();
}

/* ================================================================
   Texture handles
   ================================================================ */

intptr_t rl_load_texture(const char *path)
{
    Texture2D *t = (Texture2D *)malloc(sizeof(Texture2D));
    if (!t) return 0;
    *t = LoadTexture(path);
    return (intptr_t)(void *)t;
}

intptr_t rl_load_texture_n(const char *path, int path_len)
{
    char *safe_path = copy_string_n(path, path_len);
    if (!safe_path) return 0;

    Texture2D *t = (Texture2D *)malloc(sizeof(Texture2D));
    if (!t) {
        free(safe_path);
        return 0;
    }

    *t = LoadTexture(safe_path);
    free(safe_path);
    return (intptr_t)(void *)t;
}

void rl_unload_texture(intptr_t tex)
{
    Texture2D *t = tex_ptr(tex);
    if (!t) return;
    UnloadTexture(*t);
    free(t);
}

int rl_texture_width(intptr_t tex)
{
    Texture2D *t = tex_ptr(tex);
    return t ? t->width : 0;
}

int rl_texture_height(intptr_t tex)
{
    Texture2D *t = tex_ptr(tex);
    return t ? t->height : 0;
}

void rl_draw_texture(intptr_t tex, int x, int y, int rgba_tint)
{
    Texture2D *t = tex_ptr(tex);
    if (!t) return;
    DrawTexture(*t, x, y, rgba_to_color(rgba_tint));
}

void rl_draw_texture_ex(intptr_t tex, float x, float y,
                        float rot_deg, float scale, int rgba_tint)
{
    Texture2D *t = tex_ptr(tex);
    if (!t) return;
    Vector2 pos = { x, y };
    DrawTextureEx(*t, pos, rot_deg, scale, rgba_to_color(rgba_tint));
}

void rl_draw_texture_region(intptr_t tex,
                            float sx, float sy, float sw, float sh,
                            float dx, float dy, int rgba_tint)
{
    Texture2D *t = tex_ptr(tex);
    if (!t) return;
    Rectangle src = { sx, sy, sw, sh };
    Vector2 pos = { dx, dy };
    DrawTextureRec(*t, src, pos, rgba_to_color(rgba_tint));
}

/* ================================================================
   A) 2D sprite transforms (DrawTexturePro)
   ================================================================ */

void rl_draw_texture_pro(intptr_t tex,
                         float sx, float sy, float sw, float sh,
                         float dx, float dy, float dw, float dh,
                         float ox, float oy,
                         float rot_deg, int rgba_tint)
{
    Texture2D *t = tex_ptr(tex);
    if (!t) return;
    Rectangle src  = { sx, sy, sw, sh };
    Rectangle dest = { dx, dy, dw, dh };
    Vector2 origin = { ox, oy };
    DrawTexturePro(*t, src, dest, origin, rot_deg, rgba_to_color(rgba_tint));
}

/* ================================================================
   B) Procedural textures (create / update from packed RGBA int[])
   ================================================================ */

/* Convert Disturb int[] (each element is intptr_t = 64-bit holding
   packed 0xRRGGBBAA) into a flat unsigned char RGBA8 buffer.
   Uses a caller-provided output buffer of size pixel_count*4 bytes. */
static void unpack_pixels(const void *int_array, unsigned char *out,
                          int pixel_count)
{
    /* Disturb int[] stores each element as intptr_t (8 bytes on 64-bit).
       The void* we receive from FFI points to the raw bytes of the list. */
    const char *src = (const char *)int_array;
    for (int i = 0; i < pixel_count; i++) {
        intptr_t v = 0;
        memcpy(&v, src + (size_t)i * sizeof(intptr_t), sizeof(intptr_t));
        unsigned int u = (unsigned int)v;
        out[i * 4 + 0] = (unsigned char)((u >> 24) & 0xFF); /* R */
        out[i * 4 + 1] = (unsigned char)((u >> 16) & 0xFF); /* G */
        out[i * 4 + 2] = (unsigned char)((u >>  8) & 0xFF); /* B */
        out[i * 4 + 3] = (unsigned char)( u        & 0xFF); /* A */
    }
}

intptr_t rl_make_texture_rgba8(int w, int h, intptr_t pixels,
                               int pixel_count)
{
    if (w <= 0 || h <= 0 || pixel_count != w * h || !pixels) return 0;

    size_t buf_size = (size_t)pixel_count * 4;
    unsigned char *buf = (unsigned char *)malloc(buf_size);
    if (!buf) return 0;

    unpack_pixels((const void *)pixels, buf, pixel_count);

    Image img = {
        .data    = buf,
        .width   = w,
        .height  = h,
        .mipmaps = 1,
        .format  = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
    };

    Texture2D *t = (Texture2D *)malloc(sizeof(Texture2D));
    if (!t) { free(buf); return 0; }

    *t = LoadTextureFromImage(img);
    UnloadImage(img); /* frees buf */
    return (intptr_t)(void *)t;
}

void rl_update_texture_rgba8(intptr_t tex, intptr_t pixels,
                             int pixel_count)
{
    Texture2D *t = tex_ptr(tex);
    if (!t || !pixels || pixel_count <= 0) return;
    if (pixel_count != t->width * t->height) return;

    size_t buf_size = (size_t)pixel_count * 4;
    unsigned char *buf = (unsigned char *)malloc(buf_size);
    if (!buf) return;

    unpack_pixels((const void *)pixels, buf, pixel_count);
    UpdateTexture(*t, buf);
    free(buf);
}

/* ================================================================
   C) Text measurement + custom fonts
   ================================================================ */

static Font *font_ptr(intptr_t handle)
{
    return (Font *)(void *)handle;
}

int rl_measure_text(const char *text, int font_size)
{
    return MeasureText(text, font_size);
}

int rl_measure_text_n(const char *text, int text_len, int font_size)
{
    char *safe_text = copy_string_n(text, text_len);
    int out = 0;
    if (!safe_text) return 0;
    out = MeasureText(safe_text, font_size);
    free(safe_text);
    return out;
}

intptr_t rl_load_font(const char *path)
{
    Font *f = (Font *)malloc(sizeof(Font));
    if (!f) return 0;
    *f = LoadFont(path);
    return (intptr_t)(void *)f;
}

intptr_t rl_load_font_n(const char *path, int path_len)
{
    char *safe_path = copy_string_n(path, path_len);
    if (!safe_path) return 0;
    Font *f = (Font *)malloc(sizeof(Font));
    if (!f) { free(safe_path); return 0; }
    *f = LoadFont(safe_path);
    free(safe_path);
    return (intptr_t)(void *)f;
}

void rl_unload_font(intptr_t font)
{
    Font *f = font_ptr(font);
    if (!f) return;
    UnloadFont(*f);
    free(f);
}

int rl_measure_text_ex(intptr_t font, const char *text,
                       float font_size, float spacing)
{
    Font *f = font_ptr(font);
    if (!f) return 0;
    Vector2 sz = MeasureTextEx(*f, text, font_size, spacing);
    return (int)sz.x;
}

int rl_measure_text_ex_n(intptr_t font, const char *text, int text_len,
                         float font_size, float spacing)
{
    Font *f = font_ptr(font);
    char *safe_text = copy_string_n(text, text_len);
    int out = 0;
    if (!f || !safe_text) { free(safe_text); return 0; }
    out = (int)MeasureTextEx(*f, safe_text, font_size, spacing).x;
    free(safe_text);
    return out;
}

void rl_draw_text_ex(intptr_t font, const char *text,
                     float x, float y, float font_size,
                     float spacing, int rgba)
{
    Font *f = font_ptr(font);
    if (!f) return;
    Vector2 pos = { x, y };
    DrawTextEx(*f, text, pos, font_size, spacing, rgba_to_color(rgba));
}

void rl_draw_text_ex_n(intptr_t font, const char *text, int text_len,
                       float x, float y, float font_size,
                       float spacing, int rgba)
{
    Font *f = font_ptr(font);
    char *safe_text = copy_string_n(text, text_len);
    if (!f || !safe_text) { free(safe_text); return; }
    Vector2 pos = { x, y };
    DrawTextEx(*f, safe_text, pos, font_size, spacing, rgba_to_color(rgba));
    free(safe_text);
}

/* ================================================================
   D) 2D camera
   ================================================================ */

static Camera2D *cam_ptr(intptr_t handle)
{
    return (Camera2D *)(void *)handle;
}

intptr_t rl_camera2d_create(float offset_x, float offset_y,
                            float target_x, float target_y,
                            float rotation, float zoom)
{
    Camera2D *c = (Camera2D *)malloc(sizeof(Camera2D));
    if (!c) return 0;
    c->offset   = (Vector2){ offset_x, offset_y };
    c->target   = (Vector2){ target_x, target_y };
    c->rotation = rotation;
    c->zoom     = zoom;
    return (intptr_t)(void *)c;
}

void rl_camera2d_set(intptr_t cam,
                     float offset_x, float offset_y,
                     float target_x, float target_y,
                     float rotation, float zoom)
{
    Camera2D *c = cam_ptr(cam);
    if (!c) return;
    c->offset   = (Vector2){ offset_x, offset_y };
    c->target   = (Vector2){ target_x, target_y };
    c->rotation = rotation;
    c->zoom     = zoom;
}

void rl_camera2d_begin(intptr_t cam)
{
    Camera2D *c = cam_ptr(cam);
    if (!c) return;
    BeginMode2D(*c);
}

void rl_camera2d_end(void)
{
    EndMode2D();
}

void rl_camera2d_destroy(intptr_t cam)
{
    Camera2D *c = cam_ptr(cam);
    if (!c) return;
    free(c);
}
