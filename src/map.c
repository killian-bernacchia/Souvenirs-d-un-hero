#include "map.h"
#include <stdio.h>
#include <stdlib.h>

#define EMPTY   0x00000000
#define SOLID   0x000000ff
#define THROUGH 0x663931ff
#define LADDER  0xdf7126ff

#define ENNEMY  0x000003ff
#define MEMORY  0xffffffff

//tileMap of the game, it stores the type of each tile
//size = mapWidth * mapHeight
Tile *tileMap;

//size of the map
int mapWidth;
int mapHeight;

Vector2 *ennemiesPositions;
int ennemiesCount;

Vector2 *memoriesPositions;
int memoriesCount;

bool isMapLoaded = false;

Texture2D textureLadder;
Texture2D textureSolid;
Texture2D textureThrough;
Texture2D textureEmpty;

void LoadTilesTextures(void);
void UnloadTilesTextures(void);


void map(void)
{
    return;
}

//It loads a png file and converts it to a map
//The color of the pixel determines the type of tile
void LoadMap(const char *filename)
{
    printf("Loading map: %s\n", filename);

    if(isMapLoaded)
    {
        printf("Map already loaded, unloading\n");
        UnloadMap();
    }

    Image image = LoadImage(filename);
    mapWidth = image.width;
    mapHeight = image.height;

    LoadTilesTextures();
    tileMap = (Tile *) malloc( mapWidth * mapHeight * sizeof(Tile) );


    for ( int y = 0; y < mapHeight; y++ )
    {
        Tile *row = tileMap + y*mapWidth;
        for ( int x = 0; x < mapWidth; x++ )
        {
            Tile *tile = row + x;
            int pixel_color = ColorToInt( GetImageColor(image, x, y) );

            switch ( pixel_color )
            {
                case EMPTY: 
                    tile->type = TILE_EMPTY; 
                    tile->texture = textureEmpty;
                    break;
                case SOLID:
                    tile->type = TILE_SOLID;
                    tile->texture = textureSolid;
                    break;
                case THROUGH:
                    tile->type = TILE_THROUGH;
                    tile->texture = textureThrough;
                    break;
                case LADDER:
                    tile->type = TILE_LADDER;
                    tile->texture = textureLadder;
                    break;
                case ENNEMY:
                    tile->type = TILE_ENNEMY;
                    tile->texture = textureEmpty;
                    ennemiesCount++;
                    break;
                case MEMORY:
                    tile->type = TILE_MEMORY;
                    tile->texture = textureEmpty;
                    memoriesCount++;
                    break;
            }
        }
    }

    UnloadImage(image);

    ennemiesPositions = (Vector2 *) malloc( ennemiesCount * sizeof(Vector2) );
    memoriesPositions = (Vector2 *) malloc( memoriesCount * sizeof(Vector2) );

    int idEnnemy = 0;
    int idMemory = 0;
    for ( int y = 0; y < mapHeight; y++ )
    {
        Tile *row = tileMap + y*mapWidth;
        for ( int x = 0; x < mapWidth; x++ )
        {
            Tile *tile = row + x;
            switch (tile->type)
            {
                case TILE_EMPTY: break;
                case TILE_SOLID: break;
                case TILE_THROUGH: break;
                case TILE_LADDER: break;
                case TILE_ENNEMY:
                    ennemiesPositions[idEnnemy++] = (Vector2){x*TILE_SIZE + TILE_SIZE/2, y*TILE_SIZE - TILE_SIZE/2};
                    tile->type = TILE_EMPTY;
                    break;
                case TILE_MEMORY:
                    memoriesPositions[idMemory++] = (Vector2){x*TILE_SIZE + TILE_SIZE/2, y*TILE_SIZE - TILE_SIZE/2};
                    tile->type = TILE_EMPTY;
                    break;
                default: break; // Add a default case to handle any other enumeration values
            }
        }
    }

    isMapLoaded = true;
}

void UnloadMap(void)
{
    if(!isMapLoaded)
    {
        printf("No map loaded\n");
        return;
    }
    free(tileMap);
    free(ennemiesPositions);
    free(memoriesPositions);

    UnloadTilesTextures();
    isMapLoaded = false;
}

void DrawMap(Camera2D camera)
{
    Vector2 offset = camera.offset;

    BeginMode2D(camera);    
        for(int y = 0; y < mapHeight; y++)
        {
            for(int x = 0; x < mapWidth; x++)
            {
                Tile *tile = tileMap + y*mapWidth + x;
                DrawTexture(tile->texture, x*TILE_SIZE, y*TILE_SIZE, WHITE);
            }
        }
    EndMode2D();

}

void PrintMapInt(void)
{
    for ( int y = 0; y < mapHeight; y++ )
    {
        Tile *row = tileMap + y*mapWidth;
        for ( int x = 0; x < mapWidth; x++ )
        {
            Tile *tile = row + x;
            printf("%i ", tile->type);
        }
        printf("\n");
    }
}

void PrintHexPng(const char *filename)
{
    Image image = LoadImage(filename);
    for ( int y = 0; y < image.height; y++ )
    {
        for ( int x = 0; x < image.width; x++ )
        {
            Color color = GetImageColor(image, x, y);
            printf("0x%08x ", ColorToInt(color));
        }
        printf("\n");
    }
    UnloadImage(image);
}

void LoadTilesTextures(void)
{
    textureEmpty = LoadTexture("resources/empty.png");
    textureSolid = LoadTexture("resources/solid.png");
    textureThrough = LoadTexture("resources/through.png");
    textureLadder = LoadTexture("resources/ladder.png");
}

void UnloadTilesTextures(void)
{
    UnloadTexture(textureLadder);
    UnloadTexture(textureSolid);
    UnloadTexture(textureThrough);
    UnloadTexture(textureEmpty);
}
