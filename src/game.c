#include "raylib.h"
#include "game.h"

State previous_state = STATE_HOME;
State state = STATE_HOME;
State next_state = STATE_HOME;

void game(void)
{
    switch (state)
    {
    case STATE_HOME:
        next_state = UpdateHome();
        DrawHome();
        break;

    case STATE_MENU:
        menu();
        break;

    case STATE_SETTINGS:
        settings();
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