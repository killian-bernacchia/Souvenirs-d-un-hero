#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct {
    Vector2 position;
    float speed;
    bool isJumping;
} Player;


Player createPlayer(float x, float y, float speed);


void moveLeft(Player *player);
void moveRight(Player *player);
void jump(Player *player);

#endif 