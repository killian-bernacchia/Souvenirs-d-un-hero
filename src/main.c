#include "raylib.h"
#include "global.h"
#include "game.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
	
    InitWindow(screenWidth, screenHeight, "raylib");

    SetTargetFPS(fps);               // Set our game to run at 60 frames-per-second
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
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
