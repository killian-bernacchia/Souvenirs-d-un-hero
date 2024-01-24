#include "pause.h"
#include "global.h"
#include "raylib.h"
Rectangle Resume = {0};
Rectangle Quit = {0};
bool settingsSetted1 = false;
int valeurDeDepart1;


void DrawPause(void)
{   
    BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangleRec(Resume, GRAY);
        DrawRectangleRec(Quit, GRAY);
        DrawText(TextFormat("Pause"),  screenWidth/2 - 75 , 25, 41, BLACK);
        DrawText(TextFormat("Resume"),  valeurDeDepart1 +175, 250, 41, BLACK);
        DrawText(TextFormat("Quit"),  valeurDeDepart1+ 200 , 450, 41, BLACK);


       
       
    EndDrawing();
}
State UpdatePause(void){
    Vector2 mouse;
    valeurDeDepart1 = screenWidth/2  - 250;
    if(!settingsSetted1)
    {

        Resume = (Rectangle) { valeurDeDepart1, 220, 500, 100};
        Quit = (Rectangle) { valeurDeDepart1, 420, 500, 100};
        settingsSetted1 = true;
    }
     if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouse.x = GetMouseX();
            mouse.y = GetMouseY();
            if (CheckCollisionPointRec(mouse, Resume)){
                return STATE_GAMEPLAY;
            }
            
            if (CheckCollisionPointRec(mouse, Quit)){
                exitGame = false;
            }   
     }
    return STATE_PAUSE;
}