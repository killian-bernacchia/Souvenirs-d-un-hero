#include "raylib.h"
#include "global.h"
#include "game.h"

const int screenHeight = 720;
const int screenWidth = 1280;
int  fps = 0;
float volumeMusique = 0.9f;
float volumeDialogue = 0.9f;


int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
	int fps = 0;
    InitWindow(screenWidth, screenHeight, "raylib");
    InitAudioDevice();              // Initialize audio device

    SetTargetFPS(fps); 
    SetExitKey(0);              
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {  
        // Update
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        //DrawGame();
        //----------------------------------------------------------------------------------
        
        game();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
