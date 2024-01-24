#include "raylib.h"
#include "player.h"
#include "stdio.h"
#include <math.h>
#include <stdlib.h>

#define GRAVITY 38.0f   //pixels per second per second
#define JUMP_SPD 8.0f
#define MOUV_SPD 80.0f
#define TIME_FACTOR 40.0f
#define MAX_SPEED 20.0f

Texture2D playerTexture;
Texture2D playerGreyTexture;
Texture2D memoryTexture;

Memory *memories;

void LoadPlayer(Player *player)
{
    playerTexture = LoadTexture("resources/feu_follet_frame1.png");
    playerGreyTexture = LoadTexture("resources/feu_follet_gris.png");
    player->position = (Vector2){ 0,0 };
    player->speed = (Speed){ 0, 0 };
    player->camera = (Camera2D){ 0 };
    player->camera.target = (Vector2){ 0, 0 };
    player->camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    player->camera.rotation = 0.0f;
    player->camera.zoom = 1.0f;
    player->life = 45.0f;
    player->scale = 0.1f;
    player->texture = playerTexture;
    player->hitbox = (Rectangle){ 0 };
    player->hitbox.x = -player->texture.width*player->scale/2;
    player->hitbox.y = -player->texture.height*player->scale/2;
    player->hitbox.width = player->texture.width*player->scale;
    player->hitbox.height = player->texture.height*player->scale;

    memoryTexture = LoadTexture("resources/memory.png");
    memories = (Memory*)malloc(sizeof(Memory)*memoriesCount);
    for(int id = 0; id < memoriesCount; id++)
    {
        memories[id].position = memoriesPositions[id];
        printf("%i %i\n", (int)memories[id].position.x, (int)memories[id].position.y);
        memories[id].texture = memoryTexture;
        memories[id].scale = 0.1f;
        memories[id].hitbox = (Rectangle){ 0 };
        memories[id].hitbox.x = -memories[id].texture.width*memories[id].scale/2;
        memories[id].hitbox.y = -memories[id].texture.height*memories[id].scale/2;
        memories[id].hitbox.width = memories[id].texture.width*memories[id].scale;
        memories[id].hitbox.height = memories[id].texture.height*memories[id].scale;
        memories[id].puls = GetRandomValue(25, 50)/100.0f;
        memories[id].isAlive = true;
    }
}

void UnloadPlayer(Player *player)
{
    UnloadTexture(player->texture);
    UnloadTexture(memoryTexture);
    free(memories);
}

void DrawPlayer(Player *player)
{
    Vector2 position = player->position;
    position.x -= player->scale*player->texture.width/2;
    position.y -= player->scale*player->texture.height/2 + cosf(GetTime()*2*PI*0.4f)*7.0f - 6.0f;

    float fade = 255*player->life/30.0f + 10.0f;
    if(fade > 254.9f) fade = 254.9f;
    printf("fade : %f\n", fade);
    Color fadeColor = (Color){ 255, 255, 255, (int)fade };
    BeginMode2D(player->camera);
        DrawTextureEx(playerGreyTexture, position, 0.0f, player->scale, WHITE);
        DrawTextureEx(player->texture, position, 0.0f, player->scale, fadeColor);
    EndMode2D();

    for(int id = 0; id < memoriesCount; id++)
    {
        if(! memories[id].isAlive) continue;
        Vector2 position = memories[id].position;
        position.x -= memories[id].scale*memories[id].texture.width/2;
        position.y -= memories[id].scale*memories[id].texture.height/2 + cosf(GetTime()*2*PI*memories[id].puls)*4.0f;
        BeginMode2D(player->camera);
            DrawTextureEx(memories[id].texture, position, 0.0f, memories[id].scale, WHITE);
        EndMode2D();
    }
}

void UpdateSpeed(Player *player, Seconds delta)
{
    if(IsKeyDown(KEY_A))
    {
        player->speed.x = -MOUV_SPD*delta;
    }
    else if(IsKeyDown(KEY_D))
    {
        player->speed.x = MOUV_SPD*delta;
    }
    else
    {
        player->speed.x = 0.0f;
    }
    player->speed.y += GRAVITY*delta/TIME_FACTOR;

    /*
    if(IsKeyDown(KEY_W))
    {
        player->speed.y = -MOUV_SPD*delta;
    }
    else if(IsKeyDown(KEY_S))
    {
        player->speed.y = MOUV_SPD*delta;
    }
    */

    if(player->speed.x > MAX_SPEED)
    {
        player->speed.x = MAX_SPEED;
    }
    else if(player->speed.x < -MAX_SPEED)
    {
        player->speed.x = -MAX_SPEED;
    }

    if(player->speed.y > MAX_SPEED)
    {
        player->speed.y = MAX_SPEED;
    }
    else if(player->speed.y < -MAX_SPEED)
    {
        player->speed.y = -MAX_SPEED;
    }

    if(IsKeyPressed(KEY_SPACE))
    {
        player->speed.y = -JUMP_SPD*TIME_FACTOR;
    }
}

void UpdatePosition(Player *player, Seconds delta)
{
    player->position.x += player->speed.x*delta;
    player->position.y += player->speed.y*delta;
}

void CheckCollision(Player *player)
{    
    if(player->position.y > mapHeight*TILE_SIZE )
    {
        //game over
        player->position.y = mapHeight*TILE_SIZE;
        player->speed.y = 0.0f;
    }

    for(int y = 0; y < mapHeight; y++)
    {
        for(int x = 0; x < mapWidth; x++)
        {
            Tile *tile = tileMap + y*mapWidth + x;
            if(tile->type != TILE_EMPTY)
            {
                Rectangle tileHitbox = (Rectangle){ x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE };
                Rectangle playerHitbox = (Rectangle){ 0 };
                playerHitbox.x = player->position.x + player->hitbox.x;
                playerHitbox.y = player->position.y + player->hitbox.y;
                playerHitbox.width = player->hitbox.width;
                playerHitbox.height = player->hitbox.height;
                if(CheckCollisionRecs(playerHitbox, tileHitbox))
                {
                    //Collision from bottom
                    if(player->speed.y < 0.0f)
                    {
                        player->position.y = tileHitbox.y + tileHitbox.height + player->hitbox.height/2;
                        player->speed.y = 0.0f;
                    }
                    //Collision from top
                    else if(player->speed.y >= 0.0f)
                    {
                        player->position.y = tileHitbox.y - player->hitbox.height/2;
                        player->speed.y = 0.0f;
                    }                    
                }
            }
        }
    }

    for(int id = 0; id < memoriesCount; id++)
    {
        if(!memories[id].isAlive) continue;
        Rectangle memoryHitbox = (Rectangle){ 0 };
        memoryHitbox.x = memories[id].position.x + memories[id].hitbox.x;
        memoryHitbox.y = memories[id].position.y + memories[id].hitbox.y;
        memoryHitbox.width = memories[id].hitbox.width;
        memoryHitbox.height = memories[id].hitbox.height;

        Rectangle playerHitbox = (Rectangle){ 0 };
        playerHitbox.x = player->position.x + player->hitbox.x;
        playerHitbox.y = player->position.y + player->hitbox.y;
        playerHitbox.width = player->hitbox.width;
        playerHitbox.height = player->hitbox.height;
        if(CheckCollisionRecs(playerHitbox, memoryHitbox))
        {
            printf("Memory %i collected\n", id);
            memories[id].isAlive = false;
            player->life += 10.0f;
        }
    }

}

void UpdatePlayerCamera(Player *player)
{
    Vector2 position = player->position;
    /*
    Vector2 delta = { position.x - player->camera.target.x, position.y - player->camera.target.y };
    player->camera.target.x += delta.x/90.0f;
    player->camera.target.y += delta.y/90.0f;
    */
    player->camera.target = position;
}

void UpdatePlayer(Player *player, Seconds delta)
{
    player->life -= delta;
    if(player->life <= 0.0f)
    {
        player->life = 0.0f;
    }
    delta *= TIME_FACTOR;
    UpdateSpeed(player, delta);
    UpdatePosition(player, delta);
    CheckCollision(player);
    UpdatePlayerCamera(player);
}