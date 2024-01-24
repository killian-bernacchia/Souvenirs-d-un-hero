#include "parallax.h"
#include "raylib.h"
#include "global.h"
#include <stdio.h>

float backgroundPositionX = 0.0f;
float backgroundPositionY = 0.0f;
float coeficient = -0.2f;

Texture backgroundMountain;
Texture backgroundForest;
Texture backgroundHole;


int countUpdate = 0;
/**
* Initialise le parallaxe et lance son animation
* Attention, charge les photos donc prend beaucoup de ressources
*/
void InitParallax(void)
{        
    // int HeightBackgroundResize = screenHeight;
    // int WigthBackgroundResize = screenWidth;

    //Création des textures à partir des images (nesemble pas necessaire)
    backgroundMountain = LoadTexture("resources/backgrounds/mountain_bg_V3.png");
    backgroundForest = LoadTexture("resources/backgrounds/forest_tree_V2.png");
    backgroundHole = LoadTexture("resources/backgrounds/souterains_bgV2.png");

    return;
}

void UpdateParallax(Vector2 positionJoueur)
{
    if(countUpdate++>1000){
        printf("updateParallax, backgroundPosition = %f\n", positionJoueur.x);
        countUpdate=0;
    }

    //Si l'ecran n'est pas plus loins que la fin de l'image
        //On dessine le fond en double pour lui permettre de tourner
    DrawTexture(backgroundMountain, positionJoueur.x*coeficient, positionJoueur.y*coeficient, WHITE);
    DrawTexture(backgroundMountain, positionJoueur.x*coeficient + backgroundMountain.width, positionJoueur.y*coeficient, WHITE);
    
    DrawTexture(backgroundHole, positionJoueur.x*coeficient, positionJoueur.y*coeficient+2200, WHITE);
    DrawTexture(backgroundHole, positionJoueur.x*coeficient + backgroundHole.width, positionJoueur.y*coeficient+2200, WHITE);

    DrawTexture(backgroundForest, positionJoueur.x*coeficient, positionJoueur.y*coeficient+1100, WHITE);
    DrawTexture(backgroundForest, positionJoueur.x*coeficient + backgroundForest.width, positionJoueur.y*coeficient+1100, WHITE);

   // DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE);

    //On fait avancer le fond
    // backgroundPositionX -= 0.1f;

    //Todo : le régler sur la position du joueur
    //On change la position du bakground et on vérifie s'il faut 
    // if (backgroundPositionX <= -backgroundMountain.width*2) backgroundPositionX = 0;
    return;
} //Ajouter la position des joueurs

/**
* Decharge toutes les images
*/
void CloseParallax()
{
    
    UnloadTexture(backgroundMountain);
    UnloadTexture(backgroundForest);
    UnloadTexture(backgroundHole);
}