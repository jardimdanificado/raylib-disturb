#include "raylib_disturb.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdint.h>

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

/* ================================================================
   Window / timing
   ================================================================ */

int rl_init_window(int w, int h, const char *title)
{
    InitWindow(w, h, title);
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
