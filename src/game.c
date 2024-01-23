#include "raylib.h"
#include "game.h"
#include "home.h"
#include "menu.h"
#include "map.h"
#include "settings.h"
#include "end_game.h"

State state = STATE_HOME;

void game(void)
{

    switch (state)
    {
    case STATE_HOME:
        home();
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


}

// void DrawGame(void){

//     BeginDrawing();
//         DrawMap();
//     EndDrawing();

// }