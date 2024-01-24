#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "map.h"
#include "global.h"

typedef enum Action { ACTION_RUNNING, ACTION_FALLING, ACTION_STANDING } Action;
typedef enum Direction { DIRECTION_LEFT, DIRECTION_RIGHT } Direction;

typedef struct {
    Vector2 position;    
    Speed speed;
    Camera2D camera;
    Seconds life;
    Texture2D texture;
    float scale;
    Rectangle hitbox;
} Player;

typedef struct Memory {
    Vector2 position;
    Texture2D texture;
    float scale;
    Rectangle hitbox;
    float puls;
    bool isAlive;
} Memory;



void LoadPlayer(Player *player);
void UnloadPlayer(Player *player);

void DrawPlayer(Player *player);

void UpdateSpeed(Player *player, Seconds delta);

void UpdatePosition(Player *player, Seconds delta);

void CheckCollision(Player *player);

void UpdatePlayerCamera(Player *player);

void UpdatePlayer(Player *player, Seconds delta);

#endif 