#include "raylib.h"
#include "global.h"
#include "game.h"
#include "parallax.h"


const int screenHeight = 720;
const int screenWidth = 1280;
int  fps = 0;
float volumeMusique = 0.9f;
float volumeDialogue = 0.9f;
bool exitGame = true;


int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
	int fps = 0;
    InitWindow(screenWidth, screenHeight, "Souvenirs d'un héro");

    InitAudioDevice();              // Initialize audio device

    //Initialise parallax
    InitParallax();

    SetTargetFPS(fps); 

    SetExitKey(0);
//--------------------------------------------------------------------------------------

    current_music = LoadMusicStream("resources/Sound_fond.mp3");
    PlayMusicStream(current_music);
     
         
   
    
    //PlayMusicStream(current_music);
     
// Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {  

    SetExitKey(0);             
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose() && exitGame != false )    // Detect window close button or ESC key
    { 
        // Update
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        //DrawGame();
        //----------------------------------------------------------------------------------

        
        game();
        UpdateMusicStream(current_music);
        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();
    CloseParallax();
    CloseWindow();        // Close window and OpenGL context
    
    //--------------------------------------------------------------------------------------


    return 0;
}}
