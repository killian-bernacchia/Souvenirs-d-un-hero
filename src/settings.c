#include "settings.h"
#include "raylib.h"
#include <stdio.h>
#include "global.h"

bool settingsSetted = false;
Rectangle Fps = {0};
Rectangle FpsValue = {0};
Rectangle SoundMusique = {0};
Rectangle SoundMusiqueValue = {0};
Rectangle SoundEffect = {0};
Rectangle SoundEffectValue = {0};

void DrawSettings(void)
{
    BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangleRec(Fps, GRAY);
        DrawText("FPS Limiter:",screenWidth/2 -600 , 75, 41, BLACK);
        DrawRectangleRec(FpsValue, RED);
        

        DrawRectangleRec(SoundMusique,  GRAY);
        DrawText("Musique", screenWidth/2 -600, 245, 41, BLACK);
        DrawRectangleRec(SoundMusiqueValue, RED);
        
        DrawRectangleRec(SoundEffect,  GRAY);
        DrawText("Dialogue: ",screenWidth/2 - 600, 445, 41, BLACK);
        DrawRectangleRec(SoundEffectValue, RED);
        
    EndDrawing();
}
State UpdateSettings(void){
    if(!settingsSetted)
    {
        Fps = (Rectangle) {screenWidth/2  - 250, 50, 500, 100};
        FpsValue = (Rectangle) {screenWidth/2 -250, 50, 0, 100};
        SoundMusique = (Rectangle) {screenWidth/2 -250, 220, 500, 100};
        SoundMusiqueValue = (Rectangle) {screenWidth/2 -250, 220, 0, 100};
        SoundEffect = (Rectangle) {screenWidth/2 -250, 420, 500, 100};
        SoundEffectValue = (Rectangle) {screenWidth/2 -250 , 420, 0, 100};
        settingsSetted = true;
    }
    Vector2 mouse;
    //InitAudioDevice();  
    //int valeurFps = 0; 
    //int valeurSoundMusique =0;
   // int valeurSoundEffect =0;
    int valeurMax =  500;
    Music music = LoadMusicStream("resources/Audiomachine - Return of the King.mp3");;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mouse.x = GetMouseX();
            mouse.y = GetMouseY();
            if (CheckCollisionPointRec(mouse, Fps)){
  
 
                FpsValue.width = mouse.x - (screenWidth/2 -250) ;

            }   
            if (CheckCollisionPointRec(mouse, SoundMusique)){

                SoundMusiqueValue.width = mouse.x - (screenWidth/2 -250) ;
            }
             
            if (CheckCollisionPointRec(mouse, SoundEffect)){

                SoundEffectValue.width = mouse.x - (screenWidth/2 -250) ;
            }

    }
    UnloadMusicStream(music);   // Unload music stream buffers from RAM

    //CloseAudioDevice(); ;
    return STATE_SETTINGS;
   
}      