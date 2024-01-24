#include "game.h"

State previous_state = STATE_END_GAME;
State state = STATE_HOME;
State next_state = STATE_HOME;
bool game_over = false;

Music current_music;

void game(void)
{
    switch (state)
    {
    case STATE_HOME:
        previous_state = state;
        next_state = UpdateHome();
        if(next_state!=state)
            break;
        DrawHome();
        break;

    case STATE_MENU:
        next_state = UpdateMenu();
        if(next_state!=state)
            break;
        DrawMenu();
        break;

    case STATE_SETTINGS:
        next_state = UpdateSettings();
        if(next_state!=state)
            break;
        DrawSettings();
        break;
    
    case STATE_GAMEPLAY:
        next_state = UpdateGameplay();

        if(next_state!=state)
            break;

        DrawGameplay();
        break;
    
    case STATE_GAMEPLAY:
        next_state = UpdateGameplay();

        if(next_state!=state)
            break;

        DrawGameplay();
        break;

    case STATE_END_GAME:
        end_game();
        break;
    
    default:
        break;
    }

    

    previous_state = state;
    state = next_state;
}


