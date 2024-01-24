#include "raylib.h"
#include "player.h"

#define GRAVITY 38.0f   //pixels per second per second
#define JUMP_SPD 8.0f
#define MOUV_SPD 80.0f
#define TIME_FACTOR 40.0f
#define MAX_SPEED 20.0f

Texture2D playerTexture;

void LoadPlayer(Player *player)
{
    player->position = (Vector2){ 0,0 };
    player->speed = (Speed){ 0, 0 };
    player->camera = (Camera2D){ 0 };
    player->camera.target = (Vector2){ 0, 0 };
    player->camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    player->camera.rotation = 0.0f;
    player->camera.zoom = 1.0f;
    player->life = 30.0f;
    player->scale = 0.1f;
    player->texture = LoadTexture("resources/feu_follet_frame1.png");
    player->hitbox = (Rectangle){ 0 };
    player->hitbox.x = -player->texture.width*player->scale/2;
    player->hitbox.y = -player->texture.height*player->scale/2;
    player->hitbox.width = player->texture.width*player->scale;
    player->hitbox.height = player->texture.height*player->scale;
}

void UnloadPlayer(Player *player)
{
    UnloadTexture(player->texture);
}

void DrawPlayer(Player *player)
{
    Vector2 position = player->position;
    position.x -= player->scale*player->texture.width/2;
    position.y -= player->scale*player->texture.height/2;
    BeginMode2D(player->camera);
        DrawTextureEx(player->texture, position, 0.0f, player->scale, WHITE);
    EndMode2D();
}

void UpdateSpeed(Player *player, Seconds delta)
{
    if(IsKeyDown(KEY_LEFT))
    {
        player->speed.x = -MOUV_SPD*delta;
    }
    else if(IsKeyDown(KEY_RIGHT))
    {
        player->speed.x = MOUV_SPD*delta;
    }
    else
    {
        player->speed.x = 0.0f;
    }
    player->speed.y += GRAVITY*delta/TIME_FACTOR;

    if(IsKeyDown(KEY_UP))
    {
        player->speed.y = -MOUV_SPD*delta;
    }
    else if(IsKeyDown(KEY_DOWN))
    {
        player->speed.y = MOUV_SPD*delta;
    }

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
                        player->position.y = tileHitbox.y + tileHitbox.height;
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
    delta *= TIME_FACTOR;
    UpdateSpeed(player, delta);
    UpdatePosition(player, delta);
    CheckCollision(player);
    UpdatePlayerCamera(player);
}