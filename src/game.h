#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "menu.h"

//type
typedef enum State {STATE_HOME, STATE_MENU, STATE_SETTINGS, STATE_GAMEPLAY, STATE_END_GAME, STATE_PAUSE, STATE_CINEMATICS} State;

//GAME
extern void game(void);


//HOME
extern State UpdateHome(void);
extern void DrawHome(void);

//MENU
extern void menu(void);
extern void DrawMenu(void);
extern State UpdateMenu(void);

//SETTINGS
extern State  UpdateSettings(void);
extern void DrawSettings(void);

//GAMEPLAY
extern State UpdateGameplay(void);
extern void DrawGameplay(void);

//END_GAME
extern State UpdateEndGame(void);
extern void DrawEndGame(void);
//PAUSE
extern State UpdatePause(void);
extern void DrawPause(void);

extern State UpdateCinematics(void);
extern void DrawCinematics(void);

extern bool game_over;
extern Music current_music;

#endif