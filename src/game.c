#include "game.h"
#include "sound.h"

State previous_state = -1;
State state = STATE_HOME;
State next_state = STATE_HOME;
bool game_over = false;

void game(void)
{
    switch (state)
    {
    case STATE_CINEMATICS:
        if(previous_state!=state)
            MusicManagerLoad("resources/pantheon_music.wav");
        previous_state = state;
        next_state = UpdateCinematics();
        if(next_state!=state)
            break;
        DrawCinematics();
        break;

    case STATE_HOME:
        if(previous_state!=state)
            MusicManagerLoad("resources/Sound_fond.mp3");
        previous_state = state;
        next_state = UpdateHome();
        if(next_state!=state)
            break;
        DrawHome();
        break;

    case STATE_MENU:
        previous_state = state;
        next_state = UpdateMenu();
        if(next_state!=state)
            break;
        DrawMenu();
        break;

    case STATE_SETTINGS:
        previous_state = state;
        next_state = UpdateSettings();
        if(next_state!=state)
            break;
        DrawSettings();
        break;
    
    case STATE_GAMEPLAY:
        if(previous_state!=state)
            MusicManagerLoad("resources/eq2-pantheon.wav");
        previous_state = state;
        next_state = UpdateGameplay();
        if(next_state!=state)
            break;
        DrawGameplay();
        break;
    

    case STATE_END_GAME:
        if(previous_state!=state)
            MusicManagerLoad("resources/Sound_fond.mp3");
        previous_state = state;
        next_state = UpdateEndGame();
        if(next_state != state)
            break;

        DrawEndGame();
        break;        

        break;
    case STATE_PAUSE:
        next_state = UpdatePause();
        if(next_state!=state)
            break;
        DrawPause();
        break;
    default:
        next_state = STATE_HOME;
    }

    MusicManagerUpdate();
    previous_state = state;
    state = next_state;
}


