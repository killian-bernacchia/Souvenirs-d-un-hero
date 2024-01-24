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
Rectangle MenuBoutton = {10, 10, 124, 124};
int pourcentageFps;
int valeurDeDepart;
void DrawSettings(void)
{
    BeginDrawing();
        ClearBackground(WHITE);


        DrawRectangleRec(MenuBoutton, BLACK);
        DrawText("<", 71, 51, 41, WHITE);

        DrawRectangleRec(Fps, GRAY);
        DrawText(TextFormat("FPS Limiter: %i", fps), screenWidth/2 -600 , 75, 41, BLACK);

        DrawFPS(screenWidth/2 +200 , 10);
        DrawRectangleRec(FpsValue, RED);
        

        DrawRectangleRec(SoundMusique,  GRAY);
        DrawText("Musique", screenWidth/2 -600, 245, 41,GRAY);
        DrawRectangleRec(SoundMusiqueValue, DARKGRAY);
        
        DrawRectangleRec(SoundEffect,  GRAY);
        DrawText("Dialogue: ",screenWidth/2 - 600, 445, 41, GRAY);
        DrawRectangleRec(SoundEffectValue,DARKGRAY );
        
    EndDrawing();
}
State UpdateSettings(void){
    valeurDeDepart = screenWidth/2  - 250;
    if(!settingsSetted)
    {

        Fps = (Rectangle) { valeurDeDepart, 50, 500, 100};
        FpsValue = (Rectangle) { valeurDeDepart, 50, 0, 100};
        SoundMusique = (Rectangle) { valeurDeDepart, 220, 500, 100};
        SoundMusiqueValue = (Rectangle) { valeurDeDepart, 220, 250, 100};
        SoundEffect = (Rectangle) { valeurDeDepart, 420, 500, 100};
        SoundEffectValue = (Rectangle) { valeurDeDepart , 420, 250, 100};
        settingsSetted = true;
    }
    Vector2 mouse;
    //InitAudioDevice();  
    //int valeurFps = 0; 
    // valeurs actuelle du carrées rouge -valeur de depart) / (VALEUR MAX CARRE - valeur de derpart du carrée) * 100
    //int valeurSoundMusique =0;
   // int valeurSoundEffect =0;
    //int valeurMax =  500;
    //int valeurMin = 0;
    pourcentageFps = (FpsValue.width) /  (500 -  valeurDeDepart) * 100;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            mouse.x = GetMouseX();
            mouse.y = GetMouseY();
            if (CheckCollisionPointRec(mouse, MenuBoutton)){
                return STATE_MENU;
            }
            
            if (CheckCollisionPointRec(mouse, Fps)){
  
 
                FpsValue.width = mouse.x - ( valeurDeDepart)  ;
                fps = pourcentageFps*pourcentageFps /600 + 31;//100.0f/500.0f;
                SetTargetFPS(fps);
                

            }   
            if (CheckCollisionPointRec(mouse, SoundMusique)){

                
            }
             
            if (CheckCollisionPointRec(mouse, SoundEffect)){

                
            }

    }

    return STATE_SETTINGS;
   
}      