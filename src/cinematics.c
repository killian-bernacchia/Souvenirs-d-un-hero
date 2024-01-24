#include "cinematics.h"
#include "raylib.h"
#include "game.h"

Texture background;
bool isLoaded = false;
bool isOnFirstCinematic = true;
void cinematics(void)
{
    return;
}

State UpdateCinematics(void){
     if (IsKeyReleased(KEY_SPACE)){
        if(!isOnFirstCinematic){
            isLoaded = false;   
            return STATE_HOME;
        }else{
            UnloadTexture(background);
            isOnFirstCinematic = false;
            isLoaded = false;
        }
     }
    return STATE_CINEMATICS;

}


void DrawCinematics(void){
    DrawFPS(10,10);
    if(!isLoaded){
        if(isOnFirstCinematic){
            background = LoadTexture("resources/backgrounds/cinematique_1.png");
        } else{
            background = LoadTexture("resources/backgrounds/cinematique_2.png");
        }
        isLoaded = true;
    }

        BeginDrawing();
        
        ClearBackground(WHITE);
        DrawTexture(background, 0, 0, WHITE);

        EndDrawing();

}