#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "menu.h"
//type
typedef enum State {STATE_HOME, STATE_MENU, STATE_SETTINGS, STATE_GAMEPLAY, STATE_END_GAME} State;


//GAME
extern void game(void);


//HOME
extern State UpdateHome(void);
extern void DrawHome(void);

//MENU
extern void menu(void);
void DrawMenu(void);
State UpdateMenu(void);

//SETTINGS
extern void settings(void);

//END_GAME
extern void end_game(void);


#endif