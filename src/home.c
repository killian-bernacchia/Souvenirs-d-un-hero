#include "home.h"
#include "raylib.h"

bool textureetted = false;
bool feu_follet_loaded = false;
Image logo;
Texture2D texture;

float temps;


Texture2D feu_follet_texture1;
Texture2D feu_follet_texture2;
Texture2D feu_follet_texture3;

Texture2D current_feu_follet;

extern void DrawHome(void)
{   
    DrawFPS(10,10);
    if(!textureetted){
        textureetted = true;
        logo = LoadImage("resources/logo.png");
        ImageResize(&logo,100, 107);
        texture = LoadTextureFromImage(logo);
    }

    if(!feu_follet_loaded){ 
        feu_follet_texture1 = LoadTexture("resources/feu_follet_frame1.png");
        feu_follet_texture2 = LoadTexture("resources/feu_follet_frame2.png");
        feu_follet_texture3 = LoadTexture("resources/feu_follet_frame3.png");
        feu_follet_loaded = true;
    }

    if(0<temps && temps<=0.5){
        current_feu_follet = feu_follet_texture1;
    }
    if ((0.5<temps && temps<=1)||(1.5<temps && temps<=2)){
        current_feu_follet = feu_follet_texture2;
    }
    if ((1<temps && temps<=1.5)){
        current_feu_follet = feu_follet_texture3;
    }
    
    BeginDrawing();
        
        ClearBackground(WHITE);
        DrawTexture(texture, 590, 603, WHITE);
        DrawTexture(current_feu_follet, 10, 10, WHITE);

        DrawText("Welcome", 650, 140, 60, BLACK);
        DrawText("Press SPACE to continue", 650, 220, 30, BLACK);

        
    EndDrawing();
    
    temps += GetFrameTime();
    if (temps>2.0){
        temps = 0;
    }
}
State UpdateHome(void)
{
    if (IsKeyReleased(KEY_SPACE)){
        UnloadImage(logo);
        UnloadTexture(texture); 
        UnloadTexture(feu_follet_texture1); 
        UnloadTexture(feu_follet_texture2); 
        UnloadTexture(feu_follet_texture3);
        textureetted = false;
        feu_follet_loaded = false;
        return STATE_MENU;
    }
       
}
