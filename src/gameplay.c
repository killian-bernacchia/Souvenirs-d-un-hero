#include "gameplay.h"
#include "map.h"
#include "parallax.h"
#include "stdio.h"
#include "player.h"

Scene previous_scene = SCENE_PLATFORMER;
Scene scene = SCENE_PLATFORMER;
Scene next_scene = SCENE_PLATFORMER;

Player player = { 0 };

bool victory = false;
bool exitGamePlay = false;
bool gamePlayInitialised = false;

void gameplay(void)
{
    return;
}

State UpdateGameplay(void)
{    
    if(!gamePlayInitialised)
    {
        printf("Gameplay initialised\n");
        LoadMap("resources/tilemaptuto.png");
        //UnloadMusicStream(current_music);
        //current_music = LoadMusicStream("resources/eq2-pantheon.wav");
        
        LoadPlayer(&player);
        victory = false;
        exitGamePlay = false;
        gamePlayInitialised = true;
    }
    
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
    return (Scene)SCENE_PANTHEON;
}

void DrawPantheon(void)
{
    return;
}

//CINEMATIC_OUT
Scene UpdateCinematicOut(void)
{
    return (Scene)SCENE_CINEMATIC_OUT;
}

void DrawCinematicOut(void)
{
    EndDrawing();
    return;
}

//CINEMATIC_IN
Scene UpdateCinematicIn(void)
{
    return (Scene)SCENE_CINEMATIC_IN;
}

void DrawCinematicIn(void)
{
    EndDrawing();
    return;
}

//PLATFORMER
Scene UpdatePlatformer(void)
{
    static bool setted = false;
    static Seconds delta_t;
    if(!setted)
    {
        InitParallax();
        player.position = (Vector2){ TILE_SIZE/2, -8*TILE_SIZE };
        player.camera.target = player.position;
        delta_t = 0.0f;        
        setted = true;
    }
    else delta_t = GetFrameTime();

    UpdatePlayer(&player, delta_t);

    return SCENE_PLATFORMER;
}

void DrawPlatformer(void)
{
    BeginDrawing();
        ClearBackground(DARKGRAY);
        Vector2 position = player.position;
        position.y+=12000;
        position.x+=3800;
        UpdateParallax(position);
        DrawMap(player.camera);
        DrawPlayer(&player);
        DrawFPS(10,10);
    EndDrawing();
    return;
}

