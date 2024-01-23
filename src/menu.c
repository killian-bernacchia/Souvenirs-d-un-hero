#include "menu.h"
#include <stdio.h>

Rectangle settings_btn = {426, 144, 446, 144};
Rectangle play_btn = {426, 432, 446, 144};
Rectangle home_btn = {10, 10, 124, 124};

void DrawMenu(void)
{
    BeginDrawing();
        ClearBackground(WHITE);

        DrawRectangleRec(home_btn, BLACK);
        DrawText("<", 71, 51, 41, WHITE);

        DrawRectangleRec(settings_btn, BLACK);
        DrawText("Settings", 474, 192, 48, WHITE);

        DrawRectangleRec(play_btn, BLACK);
        DrawText("Play", 474, 480, 48, WHITE);


        
    EndDrawing();
}

State UpdateMenu(void){
    Vector2 mouse;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        mouse.x = GetMouseX();
        mouse.y = GetMouseY();

        if (CheckCollisionPointRec(mouse, home_btn))
            return STATE_HOME;
        if (CheckCollisionPointRec(mouse, settings_btn))
            return STATE_SETTINGS;
        if (CheckCollisionPointRec(mouse, play_btn))
            return STATE_GAMEPLAY;
    }
    return STATE_MENU;
}