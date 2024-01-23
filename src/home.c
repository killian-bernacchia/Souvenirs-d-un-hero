#include "home.h"
#include "raylib.h"

State UpdateHome(void)
{
    return STATE_HOME;
}

extern void DrawHome(void)
{
    BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(RAYWHITE);
    EndDrawing();
}
