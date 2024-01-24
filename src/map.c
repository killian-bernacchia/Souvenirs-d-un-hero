#include "map.h"
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 40
#define EMPTY   0x00000000
#define SOLID   0x000000ff
#define THROUGH 0x663931ff
#define LADDER  0xdf7126ff

#define ENNEMY  0x000003ff
#define MEMORY  0xffffffff

//texture of the map to draw it on the screen
Texture2D mapTexture;

//tileMap of the game, it stores the type of each tile
//size = mapWidth * mapHeight
Tile *tileMap;

//size of the map
int mapWidth;
int mapHeight;


RenderTexture2D mapRender;

Vector2 *ennemiesPositions;
int ennemiesCount;

Vector2 *memoriesPositions;
int memoriesCount;

bool isMapLoaded = false;

RenderTexture2D renderTextureLadder;
RenderTexture2D renderTextureSolid;
RenderTexture2D renderTextureThrough;
RenderTexture2D renderTextureEmpty;

void LoadTilesTextures(void);
void LoadMapTexture(void);
void UnloadTilesTextures(void);
void UnloadMapTexture(void);


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
    LoadMapTexture();

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
                    tile->render = renderTextureEmpty;
                    break;
                case SOLID:
                    tile->type = TILE_SOLID;
                    tile->render = renderTextureSolid;
                    break;
                case THROUGH:
                    tile->type = TILE_THROUGH;
                    tile->render = renderTextureThrough;
                    break;
                case LADDER:
                    tile->type = TILE_LADDER;
                    tile->render = renderTextureLadder;
                    break;
                case ENNEMY:
                    tile->type = TILE_ENNEMY;
                    ennemiesCount++;
                    break;
                case MEMORY:
                    tile->type = TILE_MEMORY;
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
    UnloadMapTexture();
    isMapLoaded = false;
}

void DrawMap(Camera2D camera)
{
    Vector2 offset = camera.offset;
    Vector2 target = camera.target;

    BeginMode2D(camera);    
        for(int x = 0; x < mapWidth; x++)
        {
            for(int y = 0; y < mapHeight; y++)
            {
                Tile *tile = tileMap + y*mapWidth + x;
                DrawTexture(tile->render.texture, x*TILE_SIZE - offset.x, y*TILE_SIZE - offset.y, WHITE);
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

void LoadTilesTextures(void)
{
    renderTextureLadder = LoadRenderTexture(TILE_SIZE, TILE_SIZE);
    renderTextureSolid = LoadRenderTexture(TILE_SIZE, TILE_SIZE);
    renderTextureThrough = LoadRenderTexture(TILE_SIZE, TILE_SIZE);
    renderTextureEmpty = LoadRenderTexture(TILE_SIZE, TILE_SIZE);

    BeginTextureMode(renderTextureLadder);
        ClearBackground(ORANGE);
    EndTextureMode();

    BeginTextureMode(renderTextureSolid);
        ClearBackground(DARKGRAY);
    EndTextureMode();
    
    BeginTextureMode(renderTextureThrough);
        ClearBackground(BROWN);
    EndTextureMode();

    BeginTextureMode(renderTextureEmpty);
        ClearBackground(BLANK);
    EndTextureMode();

}

void LoadMapTexture(void)
{
    mapRender = LoadRenderTexture(screenWidth, screenHeight);
    mapTexture = mapRender.texture;
}

void UnloadTilesTextures(void)
{
    UnloadRenderTexture(renderTextureLadder);
    UnloadRenderTexture(renderTextureSolid);
    UnloadRenderTexture(renderTextureThrough);
    UnloadRenderTexture(renderTextureEmpty);
}

void UnloadMapTexture(void)
{
    UnloadTexture(mapTexture);
    UnloadRenderTexture(mapRender);
}