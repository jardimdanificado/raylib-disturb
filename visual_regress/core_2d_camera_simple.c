#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera simple");

    Camera2D camera = { 0 };
    camera.offset = (Vector2){ 400.0f, 225.0f };
    camera.target = (Vector2){ 200.0f, 200.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode2D(camera);
                DrawRectangle(-600, 320, 1300, 800, DARKGRAY);
                DrawRectangle(80, 120, 120, 200, LIGHTGRAY);
                DrawRectangle(260, 60, 160, 260, GRAY);
                DrawRectangle(480, 180, 100, 140, LIGHTGRAY);
                DrawRectangle(180, 260, 40, 40, RED);
                DrawLine(200, -2000, 200, 2000, GREEN);
                DrawLine(-2000, 200, 2000, 200, GREEN);
            EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
