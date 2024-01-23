#include "home.h"
#include "raylib.h"

bool textureetted = false;
Image logo; 
Texture2D texture;

extern void DrawHome(void)
{   
    if(!textureetted){
        textureetted = true;
        logo = LoadImage("resources/logo.png");
        ImageResize(&logo,100, 107);
        texture = LoadTextureFromImage(logo);
    }

    
    BeginDrawing();
        
        ClearBackground(WHITE);
        DrawTexture(texture, 590, 603, WHITE);

        DrawText("Welcome", 650, 140, 60, BLACK);
        DrawText("Press SPACE to continue", 650, 220, 30, BLACK);

        
    EndDrawing();
    
    
}

State UpdateHome(void)
{
    if (IsKeyReleased(KEY_SPACE)){
        textureetted = false;
        UnloadImage(logo);
        UnloadTexture(texture); 
        return STATE_MENU;
    }
       
}
