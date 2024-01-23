#ifndef GAME_H
#define GAME_H

//type
typedef enum State {STATE_HOME, STATE_MENU, STATE_SETTINGS, STATE_END_GAME} State;


//GAME
extern void game(void);


//HOME
extern State UpdateHome(void);
extern void DrawHome(void);

//MENU
extern void menu(void);

//SETTINGS
extern void settings(void);

//END_GAME
extern void end_game(void);


#endif