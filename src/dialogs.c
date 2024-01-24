#include "dialogs.h"
#include "raylib.h"
#include "global.h"
int indexfeuxfollet = 0; 
int indexGuardien = 0; 
char* UpdateDialogueFeuxfollet(void){
    char* feuxfollet [5] = {"un hero légendaire venant prendre repos." , "Et Bien je suis …  Je suis … Je suis qui ? je ne sais plus" ,"Mais je ne vous mens pas j’ai réellement perdue la mémoire comment puis-je prouver ma fois ?", "je n’aurais qu’as donc retrouver ces brides et ma mémoire reviendras ?", "j’y veillerais."};
    return  feuxfollet[indexfeuxfollet];
    indexfeuxfollet++;
    
    
}
char* UpdateDialogueGuardien(void){
    char* guardien [5] = {"alte qui êtes vous ame en peine  ?" , "Et a qui avons nous l’honneur ?" ,"Et bien encore une âme qui essaye de s'infiltrer dans le panthéons","J’ai déjà entendue parler de cette légende ou certaine âme perdre leur mémoire durant le trajet et que les bribes de cette mémoire se retrouve éparpillée au 4 coins du chant des châtiments.", "Oui, si la légende dit vrai, mais prends garde : le chant des châtiments est rempli de créatures, en particulier les Éthérombres, dont il faut se méfier. Ils voudront aspirer ton esprit jusqu'à la dernière once de vie. Bonne chance, âme perdue."};
    return  guardien[indexGuardien];
    indexGuardien ++;
    
    
}