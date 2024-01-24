#ifndef ENEMIES_H
#define ENEMIES_H

#include "raylib.h"

Texture2D enemyTexture;

typedef struct Enemy
{
    Vector2 position;
    float pulsion;
} Enemy;


#endif