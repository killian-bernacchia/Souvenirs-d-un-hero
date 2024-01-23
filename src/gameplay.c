#include "gameplay.h"
#include "map.h"

Scene previous_scene = SCENE_PLATFORMER;
Scene scene = SCENE_PLATFORMER;
Scene next_scene = SCENE_PLATFORMER;

bool victory = false;
bool exit = false;

void gameplay(void)
{
    return;
}

State UpdateGameplay(void)
{    
    switch (scene)
    {
    case SCENE_PANTHEON:
        next_scene = UpdatePantheon();
        break;
    case SCENE_CINEMATIC_OUT:
        next_scene = UpdateCinematicOut();
        break;
    case SCENE_CINEMATIC_IN:
        next_scene = UpdateCinematicIn();
        break;
    case SCENE_PLATFORMER:
        next_scene = UpdatePlatformer();
        break;
    case SCENE_PAUSE:
        next_scene = UpdatePause();
        break;
    }

    if(game_over | victory)
        return STATE_END_GAME;
    if(exit)
        return STATE_MENU;

    return STATE_GAMEPLAY;
}

void DrawGameplay(void)
{
    if(next_scene!=scene)
        previous_scene = scene;
        scene = next_scene;
        return;

    switch (scene)
    {
    case SCENE_PANTHEON:
        DrawPantheon();
        break;
    case SCENE_CINEMATIC_OUT:
        DrawCinematicOut();
        break;
    case SCENE_CINEMATIC_IN:
        DrawCinematicIn();
        break;
    case SCENE_PLATFORMER:  
        DrawPlatformer();
        break;
    case SCENE_PAUSE:
        DrawPause();
        break;
    }

    previous_scene = scene;
    next_scene = scene;
    return;
}