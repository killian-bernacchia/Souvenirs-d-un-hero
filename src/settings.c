#include "settings.h"
#include "raylib.h"
#include <stdio.h>

Rectangle Fps = {20, 20, 100, 100};
Rectangle FpsValue = {20, 20, 50, 50};
Rectangle SoundMusique = {220, 220, 100, 100};
Rectangle SoundMusiqueValue = {220, 220, 50, 50};
Rectangle SoundEffect = {420, 420, 100, 100};
Rectangle SoundEffectValue = {420, 420, 50, 50};

void DrawSettings(void)
{
    BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangleRec(Fps, GRAY);
        DrawText("FPS Limiter:", 0, 0, 41, WHITE);
        DrawRectangleRec(FpsValue, RED);
        

        DrawRectangleRec(SoundMusique,  GRAY);
        DrawText("Musique", 200, 200, 41, WHITE);
        DrawRectangleRec(SoundMusiqueValue, RED);
        
        DrawRectangleRec(SoundEffect,  GRAY);
        DrawText("Dialogue: ", 400, 400, 41, WHITE);
        DrawRectangleRec(SoundEffectValue, RED);
        
    EndDrawing();
}
State UpdateSettings(void){
    printf("1 ");
    Vector2 mouse;
    //InitAudioDevice();  
    printf("2 ");
    //int valeurFps = 0; 
    //int valeurSoundMusique =0;
   // int valeurSoundEffect =0;
    int valeurMax = 100;
    Music music = LoadMusicStream("resources/Audiomachine - Return of the King.mp3");
    printf("3 ");
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mouse.x = GetMouseX();
            mouse.y = GetMouseY();
            if (CheckCollisionPointRec(mouse, Fps)){
               if (mouse.x >= valeurMax)
               {
                FpsValue.width = valeurMax;
                

               }
               else{
                FpsValue.width = mouse.x;
               }
               
            }   
            if (CheckCollisionPointRec(mouse, SoundMusique)){

            }
             
            if (CheckCollisionPointRec(mouse, SoundEffect)){

            }

    }
    UnloadMusicStream(music);   // Unload music stream buffers from RAM
    printf("4 ");

    //CloseAudioDevice(); 
    printf("5 ");
    return STATE_SETTINGS;
   
}      