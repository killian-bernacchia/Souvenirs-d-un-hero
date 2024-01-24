#include "pause.h"
#include "global.h"
#include "raylib.h"
Rectangle Resume = {0};
Rectangle Quit = {0};
void DrawPause(void)
{   
    BeginDrawing();
        ClearBackground(WHITE);

        DrawText(TextFormat("FPS Limiter: %i", fps), screenWidth/2 -600 , 75, 41, BLACK);

       
        DrawRectangleRec(Resume, GRAY);
        DrawRectangleRec(Quit, GRAY);
}
State UpdatePause(void){
    return STATE_PAUSE;
}