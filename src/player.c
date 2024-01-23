#include "raylib.h"
#include "player.h"
#include "raymath.h"
void player(void){

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

    Image image = LoadImage("resources/raylib_logo.png");  // Load image data into CPU memory (RAM)
    Texture2D texture = LoadTextureFromImage(image);       // Image converted to texture, GPU memory (RAM -> VRAM)
    UnloadImage(image);

    Player createPlayer(float x, float y, float speed) {
    Player player = { (Vector2){ x, y }, speed, false };
    return player;
}

// mouvement joueur 
void UpdatePlayer(Player *player) {
    if (IsKeyDown(KEY_RIGHT)) {
        player->position.x -= player->speed;
        GetFrameTime
    }
    else if (IsKeyDown(KEY_LEFT)) {
        player->position.x += player->speed;
    }

    if (IsKeyPressed(KEY_SPACE)) && !player->isJumping) {
        player->isJumping = true;
    }
}

    float forceVertical = 0;
    float gravity = 0.08;
     // gravité
    if (player->position.y < 280.0f || player->isJumping) {
        player->position.y += 5.0f; 
    }

    // Mettez à jour la position y du joueur en fonction de la logique de saut
    if (player->isJumping) {
        // Implémentez la logique de saut ici (par exemple, modifier la position y du joueur)
        // Par exemple, vous pouvez augmenter la position y pendant un certain temps, puis la diminuer pour simuler un saut.
        player->position.y -= 5.0f;  // Placeholder, ajustez selon vos besoins
    }

    // Remettez à zéro le saut lorsque le joueur touche le sol (ajoutez votre propre logique ici)
    if (player->position.y >= 280.0f) {
        player->position.y = 280.0f;
        player->isJumping = false;
    }












while (!WindowShouldClose())    // Detect window close button or ESC key
    {

























}