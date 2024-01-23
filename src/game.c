#include "raylib.h"
#include "game.h"
#include "home.h"
#include "menu.h"
#include "map.h"
#include "settings.h"
#include "end_game.h"

static enum{stat_home, stat_menu, stat_settings, stat_end_game} stat=stat_home;

void game(void)
{

    switch (stat)
    {
    case stat_home:
        home();
        break;

    case stat_menu:
        menu();
        break;

    case stat_settings:
        settings();
        break;

    case stat_end_game:
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