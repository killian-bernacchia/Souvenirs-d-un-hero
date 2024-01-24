#include "gameplay.h"
#include "map.h"

Scene previous_scene = SCENE_PLATFORMER;
Scene scene = SCENE_PLATFORMER;
Scene next_scene = SCENE_PLATFORMER;
bool victory = false;
bool exitGamePlay = false;

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
    }

    if(game_over | victory)
        return STATE_END_GAME;
    if(exitGamePlay)
        return STATE_MENU;
    if(IsKeyReleased(KEY_P))
        return STATE_PAUSE;
    
    return STATE_GAMEPLAY;
}

void DrawGameplay(void)
{
    if(next_scene!=scene)
    {
        previous_scene = scene;
        scene = next_scene;
        return;
    }

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
    }

    previous_scene = scene;
    next_scene = scene;
    return;
}



//PANTHEON
Scene UpdatePantheon(void)
{
    return (Scene){0};
}
void DrawPantheon(void)
{
    return;
}
//CINEMATIC_OUT
Scene UpdateCinematicOut(void)
{
    return (Scene){0};
}
void DrawCinematicOut(void)
{
    return;
}
//CINEMATIC_IN
Scene UpdateCinematicIn(void)
{
    return (Scene){0};
}
void DrawCinematicIn(void)
{
    return;
}
//PLATFORMER
Scene UpdatePlatformer(void)
{
    return SCENE_PLATFORMER;
}

void DrawPlatformer(void)
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
    EndDrawing();
    return;
}

