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
    InitWindow(screenWidth, screenHeight, "Souvenirs d'un héro");

    InitAudioDevice();

	int fps = 300;
    SetTargetFPS(fps); 

    SetExitKey(0);              

    current_music = LoadMusicStream("resources/eq2-pantheon.wav");
    PlayMusicStream(current_music);

    // Main game loop
    while (!WindowShouldClose() && exitGame != false )    // Detect window close button or ESC key
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
