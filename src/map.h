#ifndef MAP_H
#define MAP_H

#include "global.h"
#include "raylib.h"
#define TILE_SIZE 40    
#define SCREEN_TILE_WIDTH  32
#define SCREEN_TILE_HEIGHT 18

typedef enum TileType
{
    TILE_EMPTY = 0,
    TILE_SOLID = 1,
    TILE_THROUGH = 2,
    TILE_LADDER = 3,
    TILE_ENNEMY = 4,
    TILE_MEMORY = 5
} TileType;

typedef struct Tile
{
    TileType type;
    Texture2D texture;
} Tile;

//texture of the map to draw it on the screen
extern RenderTexture2D mapRender;

//tileMap of the game, it stores the type of each tile
//size = mapWidth * mapHeight
extern Tile *tileMap;

//size of the map
extern int mapWidth;
extern int mapHeight;

//do nothing
void map(void);

//Creates the tileMap from an png image
//Initialize ennemiesPositions and memoriesPositions
//Initialize ennemiesCount and memoriesCount
//Initialize textures
void LoadMap(const char *filename);

//Clear memory
void UnloadMap(void);

//Draw the map on the texture
void DrawMap(Camera2D camera);

//Print tiles types as int for debug purpose
void PrintMapInt(void);

//Print tiles as hex for debug purpose
void PrintHexPng(const char *filename);

#endif