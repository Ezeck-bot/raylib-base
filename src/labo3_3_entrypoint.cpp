#include "entrypoint.h"
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

// Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void)
{
    srand(time(NULL));
    const int screenWidth = 760;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Rébond");

    Color couleurs[] = {GREEN, RED, PINK, WHITE, PURPLE, GOLD};

    Rectangle balle = {400, 280, 50, 50};
    int balleSpeedX = 4;
    int balleSpeedY = 4;
    bool pause = false;
    int couleurId = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        if (!pause)
        {
            balle.x += balleSpeedX;
            balle.y += balleSpeedY;
        }

        if (((balle.x + balle.width) >= GetScreenWidth()) || (balle.x <= 0))
        {
            balleSpeedX *= -1;
            couleurId = rand() % 6;
        }

        if (((balle.y + balle.height) >= GetScreenHeight()) || (balle.y <= 0))
        {
            balleSpeedY *= -1;
            couleurId = rand() % 6;
        }

        if (IsKeyPressed(KEY_SPACE))
            pause = !pause;

        BeginDrawing();

        ClearBackground(SKYBLUE);

        DrawRectangleRec(balle, couleurs[couleurId]);

        EndDrawing();
    }

    CloseWindow();
}