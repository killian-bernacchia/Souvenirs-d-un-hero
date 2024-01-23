#include "game.h"
#include <stdio.h>
#include <stdio.h>

State previous_state = STATE_HOME;
State state = STATE_MENU;
State next_state = STATE_HOME;

void game(void)
{
    switch (state)
    {
    case STATE_HOME:
        next_state = UpdateHome();
        DrawHome();
        printf("home");
        break;

    case STATE_MENU:
        next_state = UpdateMenu();
        DrawMenu();
        printf("menu");
        break;

    case STATE_SETTINGS:
        settings();
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