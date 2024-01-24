#include "raylib.h"
#include "global.h"
#include "game.h"

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
	int fps = 0;
    InitWindow(screenWidth, screenHeight, "raylib");
    InitAudioDevice();// Initialize audio device

    SetTargetFPS(fps); 
    SetExitKey(0);

    current_music = LoadMusicStream("resources/Sound_fond.mp3");
    PlayMusicStream(current_music);
     
         
   
    
    //PlayMusicStream(current_music);
     
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {  
        
        game();
        UpdateMusicStream(current_music);
        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
