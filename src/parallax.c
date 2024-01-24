#include "parallax.h"
#include "raylib.h"
#include "global.h"


float backgroundPosition = 0.0f;
Image backgroundImage;
Texture background;
int countUpdate = 0;
/**
* Initialise le parallaxe et lance son animation
*/
void InitParallax(void)
{        
    // backgroundImage = LoadImage("resources/backgrounds/mountain_bg_V3.png");
    backgroundImage = LoadImage("resources/backgrounds/souterains_bgV2.png");
    ImageResize(&backgroundImage, screenWidth, screenHeight);
    background = LoadTextureFromImage(backgroundImage);
  
    
    
    return;
}

void UpdateParallax(void)
{
    
    if(countUpdate++>1000){
        printf("updateParallax, backgroundPosition = %i\n", backgroundPosition);
        countUpdate=0;
    }

    //On dessine le fond en double pour lui permettre de tourner
    DrawTexture(background, backgroundPosition, 0, WHITE);
    
    //On fait avancer le fond
    // backgroundPosition -= 0.1f;

    //On change la position du bakground et on vérifie s'il faut 
    if (backgroundPosition <= -background.width*2) backgroundPosition = 0;
    return;
} //Ajouter la position des joueurs

/**
* Decharge toutes les images
*/
void CloseParallax()
{
    UnloadTexture(background);
}