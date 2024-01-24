#include "dialogs.h"
#include "raylib.h"
#include "global.h"

int indexfeuxfollet = 0; 
int indexGuardien = 0; 
void UpdateDialogueFeuxfollet(){
    indexfeuxfollet++;
}
void UpdateDialogueGuardien(){
    indexGuardien ++;
}

void drawDialogueGuardien(){
    char* guardien [5] = {"alte qui êtes vous ame en peine  ?" , "Et a qui avons nous l’honneur ?" ,"Et bien encore une âme qui essaye de s'infiltrer dans le panthéons","J’ai déjà entendue parler de cette légende ou certaine âme perdre leur mémoire durant le trajet et que les bribes de cette mémoire se retrouve éparpillée au 4 coins du chant des châtiments.", "Oui, si la légende dit vrai, mais prends garde : le chant des châtiments est rempli de créatures, en particulier les Éthérombres, dont il faut se méfier. Ils voudront aspirer ton esprit jusqu'à la dernière once de vie. Bonne chance, âme perdue."};

    Rectangle play_btn = {300, 500, 446, 300};
    DrawRectangleRec(play_btn, BLACK);
    DrawText(guardien[indexGuardien], 400, 600, 48, WHITE);
}

void drawDialogueFeuFollet(){
    char* feuxfollet [5] = {"un hero légendaire venant prendre repos." , "Et Bien je suis …  Je suis … Je suis qui ? je ne sais plus" ,"Mais je ne vous mens pas j’ai réellement perdue la mémoire comment puis-je prouver ma fois ?", "je n’aurais qu’as donc retrouver ces brides et ma mémoire reviendras ?", "j’y veillerais."};

    Rectangle play_btn = {300, 500, 446, 300};
    DrawRectangleRec(play_btn, BLACK);
    DrawText(feuxfollet[indexfeuxfollet], 400, 600, 48, WHITE);
}