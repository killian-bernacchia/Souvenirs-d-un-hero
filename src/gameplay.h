#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "game.h"

typedef enum Scene {SCENE_PANTHEON, SCENE_CINEMATIC_OUT, SCENE_CINEMATIC_IN, SCENE_PLATFORMER, SCENE_PAUSE} Scene;

void gameplay(void);

//PANTHEON
Scene UpdatePantheon(void);
void DrawPantheon(void);

//CINEMATIC_OUT
Scene UpdateCinematicOut(void);
void DrawCinematicOut(void);

//CINEMATIC_IN
Scene UpdateCinematicIn(void);
void DrawCinematicIn(void);

//PLATFORMER
Scene UpdatePlatformer(void);
void DrawPlatformer(void);

//PAUSE
Scene UpdatePause(void);
void DrawPause(void);

#endif