#include "game.h"
#include <stdio.h>
#include <stdio.h>

State previous_state = STATE_END_GAME;
State state = STATE_HOME;
State next_state = STATE_HOME;

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
        printf("home");
        break;

    case STATE_MENU:
        next_state = UpdateMenu();

        if(next_state!=state)
            break;

        DrawMenu();
        printf("menu");
        break;

    case STATE_SETTINGS:
        next_state = UpdateSettings();

        if(next_state!=state)
            break;

        DrawSettings();
        printf("set");
        break;

    case STATE_END_GAME:
        end_game();
        printf("end");
        break;
    
    default:
        break;
    }

    

    previous_state = state;
    state = next_state;
}