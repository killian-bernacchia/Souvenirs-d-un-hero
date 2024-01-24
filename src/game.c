#include "game.h"
#include <stdio.h>
#include <stdio.h>

State previous_state = STATE_HOME;
State state = STATE_HOME;
State next_state = STATE_HOME;

Music current_music;


void game(void)
{
    switch (state)
    {
    case STATE_HOME:
        if (previous_state != state)
        {
            
            current_music = LoadMusicStream("resources/Sound_fond.mp3");
            PlayMusicStream(current_music);
            printf("Chargement musique home");
        }
        previous_state = state;
        next_state = UpdateHome();
        if (next_state != state)
        {
            break;
        }
        DrawHome();
        break;

    case STATE_MENU:
        if (previous_state != state)
        {
            
            current_music = LoadMusicStream("resources/m1.mp3");
            PlayMusicStream(current_music);
            printf("/////////////////////////////////////Chargement musique menu");
        }
        previous_state = state;
        next_state = UpdateMenu();
        if (next_state != state)
        {
            break;
        }
        DrawMenu();
        break;

    case STATE_SETTINGS:
        previous_state = state;
        next_state = UpdateSettings();
        if (next_state != state)
        {
            break;
        }
        DrawSettings();
        printf("/////////////////////////////////////////////set");
        break;

    case STATE_END_GAME:
        if (previous_state != state)
        {
            
            current_music = LoadMusicStream("resources/Sound_fond.mp3");
            PlayMusicStream(current_music);
        }
        end_game();
        printf("end");
        break;

    default:
        break;
    }

    UpdateMusicStream(current_music);
    previous_state = state;
    state = next_state;
}