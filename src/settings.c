#include "settings.h"
#include "raylib.h"

Rectangle Fps = {20, 20, 100, 100};
Rectangle FpsValue = {20, 20, 0, 0};
Rectangle SoundMusique = {220, 220, 100, 100};
Rectangle SoundMusiqueValue = {220, 220, 0, 0};
Rectangle SoundEffect = {420, 420, 100, 100};
Rectangle SoundEffectValue = {420, 420, 0, 0};

void DrawSettings(void)
{
    BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangleRec(Fps, BLACK);
        DrawText("FPS Limiter:", 0, 0, 41, WHITE);

        

        DrawRectangleRec(SoundMusique, BLACK);
        DrawText("Musique", 200, 200, 41, WHITE);

        DrawRectangleRec(SoundEffect, BLACK);
        DrawText("Dialogue: ", 400, 400, 41, WHITE);



        
    EndDrawing();
}
State UpdateSettings(void){
    Vector2 mouse;
    InitAudioDevice();  
    //int valeurFps = 0; 
    //int valeurSoundMusique =0;
   // int valeurSoundEffect =0;            // Initialize audio device
    int valeurMax = 100;
    Music music = LoadMusicStream("resources/Audiomachine - Return of the King.mp3");
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

    CloseAudioDevice(); 
    return STATE_SETTINGS;
   
}      