#include "entrypoint.h"
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

// Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void)
{
    srand(time(NULL));
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    const int speed = 8;
    float playerWidth = 100.0f;
    float playerHeight = 40.0f;
    bool collision = false;
    int count = 0;
    float randX = rand() % 761;
    float randY = rand() % 481;

    // init app
    InitWindow(screenWidth, screenHeight, "Cube Snake");

    Rectangle player = {400, 280, playerWidth, playerHeight};

    Rectangle nourriture = {100, 100, 50, 50};

    Rectangle boxCollision = {0};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        collision = CheckCollisionRecs(player, nourriture);

        if (collision)
            boxCollision = GetCollisionRec(player, nourriture);

        if (collision)
        {
            randX = rand() % 761;
            randY = rand() % 481;

            nourriture = {randX, randY, 50, 50};
            count++;
        }

        // Player movement
        if (IsKeyDown(KEY_UP))
        {
            playerWidth = 40.0f;
            playerHeight = 100.0f;
            // --
            player.y -= speed;
        }
        else if (IsKeyDown(KEY_RIGHT))
        {
            playerWidth = 100.0f;
            playerHeight = 40.0f;
            // --
            player.x += speed;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            playerWidth = 100.0f;
            playerHeight = 40.0f;
            // --
            player.x -= speed;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            playerWidth = 40.0f;
            playerHeight = 100.0f;
            // --
            player.y += speed;
        }
        player = {player.x, player.y, playerWidth, playerHeight};

        // cette partie je me suis fait aider par ChatGPT
        // je savais qu'il fallait vérifier si le cuble est ouhjour dans la dimension de la fenêtre
        // mais pas que je devais créer une nouvelle valeur et pour le faire reappaitre ailleur
        if (player.x > screenWidth)
        {
            player.x = -playerWidth;
        }
        if (player.x < -playerWidth)
        {
            player.x = screenWidth;
        }
        if (player.y > screenHeight)
        {
            player.y = -playerHeight;
        }
        if (player.y < -playerHeight)
        {
            player.y = screenHeight;
        }
        //--

        // ------------------------------------
        BeginDrawing();

        ClearBackground(SKYBLUE);

        DrawText(TextFormat("%s %d", "Point : ", count), 10, 10, 60, BLACK);

        DrawRectangleRec(nourriture, RAYWHITE);

        DrawRectangleRec(player, RED);

        EndDrawing();
        // ------------------------------------
    }

    CloseWindow();
}