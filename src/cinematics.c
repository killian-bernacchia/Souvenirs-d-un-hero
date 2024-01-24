#include "cinematics.h"
#include "raylib.h"
#include "game.h"
#include "dialogs.h"

Texture background;
bool isLoaded = false;
bool isOnFirstCinematic = true;
bool isGuardianSpeecking = true;
float countCinematics = 0;
int countDialogue = 0;
bool stop = false;
void cinematics(void)
{
    return;
}

State UpdateCinematics(void){
     if (IsKeyReleased(KEY_SPACE) || stop){
        if(!isOnFirstCinematic){
            UnloadTexture(background);
            isLoaded = false;   
            return STATE_HOME;
        }else{
            UnloadTexture(background);
            isOnFirstCinematic = false;
            isLoaded = false;
        }
     }
    return STATE_CINEMATICS;

}


void DrawCinematics(void){
    DrawFPS(10,10);
    if(!isLoaded){
        isLoaded = true;
        if(isOnFirstCinematic){
            background = LoadTexture("resources/backgrounds/cinematique_1.png");
        } else{
            background = LoadTexture("resources/backgrounds/cinematique_2.png");
        }
        
    }

    BeginDrawing();
    
    ClearBackground(WHITE);
    DrawTexture(background, 0, 0, WHITE);

    if(!isOnFirstCinematic){
        if(countDialogue>=9){
            stop = true;
        }else{
        countCinematics += GetFrameTime();

        if (countCinematics>2.0){
            countCinematics = 0;
        
            if(isGuardianSpeecking){
                UpdateDialogueGuardien();
                isGuardianSpeecking=false;
                countDialogue++;
            }
            else{
                UpdateDialogueFeuxfollet();
                isGuardianSpeecking=true;
                countDialogue++;
                }
                    
            } else{

            }
        }
            if(isGuardianSpeecking){
                drawDialogueGuardien();
            }else{
                drawDialogueFeuFollet();
            }
    }


    
    EndDrawing();

}