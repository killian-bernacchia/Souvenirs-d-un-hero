#include "raylib.h"
#include "global.h"
#include "game.h"


const int screenHeight = 720;
const int screenWidth = 1280;
int  fps = 60;
float volumeMusique = 0.9f;
float volumeDialogue = 0.9f;
bool exitGame = true;

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(screenWidth, screenHeight, "Souvenirs d'un héro");

    InitAudioDevice();

	int fps = 300;
    SetTargetFPS(fps); 

    SetExitKey(0);              

    // Main game loop
    while (!WindowShouldClose() && exitGame != false )    // Detect window close button or ESC key
    {  
        if(IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
        }
        if(IsKeyPressed(KEY_ESCAPE) && IsWindowFullscreen())
        {
            ToggleFullscreen();
        }
        game();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
