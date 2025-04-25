#include "entrypoint.h"
#include <raylib.h>

// Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void)
{

    const int screenWidth = 1400;
    const int screenHeight = 1000;

    // init app
    InitWindow(screenWidth, screenHeight, "Castelvania");

    SetTargetFPS(60);

    Texture2D texture = LoadTexture("Assets/drapeau4.png");
    Texture2D porte = LoadTexture("Assets/porte2.png");

    Font font = LoadFontEx("Assets/bradley-gratis.ttf", 80, 0, 0);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(SKYBLUE);

        DrawTextEx(font, "[Castelvania]", CLITERAL(Vector2){10, 10}, (float)font.baseSize, 0.0f, RED);

        // BLOC GAUCHE
        {

            DrawRectangle(50, 550, 200, 400, GRAY);

            {
                DrawRectangle(100, 650, 50, 50, RAYWHITE);
                DrawRectangle(152, 650, 50, 50, RAYWHITE);
                DrawRectangle(100, 702, 50, 50, RAYWHITE);
                DrawRectangle(152, 702, 50, 50, RAYWHITE);
            }
            //--

            DrawRectangle(225, 250, 250, 100, BLACK);

            DrawRectangle(250, 350, 200, 600, RAYWHITE);

            {
                DrawRectangle(300, 400, 50, 50, BLACK);
                DrawRectangle(352, 400, 50, 50, BLACK);
                DrawRectangle(300, 452, 50, 50, BLACK);
                DrawRectangle(352, 452, 50, 50, BLACK);
            }

            //--
            DrawRectangle(20, 500, 250, 70, BLACK);

            DrawRectangle(20, 430, 70, 70, RED);

            DrawRectangle(110, 430, 70, 70, RED);

            DrawRectangle(200, 430, 70, 70, RED);

            // drapeau
            DrawTexture(texture, 345, 80, WHITE);

            DrawTriangle(CLITERAL(Vector2){350, 140}, CLITERAL(Vector2){225, 250}, CLITERAL(Vector2){475, 250}, BLACK);
            // gauche //haut //droite
        }

        //--

        // BLOC CENTRE
        {
            // drapeau
            DrawTexture(texture, 690, 30, WHITE);

            DrawTriangle(CLITERAL(Vector2){695, 110}, CLITERAL(Vector2){570, 250}, CLITERAL(Vector2){820, 250}, RED);
            // gauche //haut //droite

            DrawRectangle(570, 250, 250, 250, RAYWHITE);

            DrawRectangle(500, 330, 70, 70, RED);

            DrawRectangle(660, 330, 70, 70, RED);

            DrawRectangle(820, 330, 70, 70, RED);

            DrawRectangle(450, 400, 500, 550, WHITE);

            DrawRectangle(470, 430, 60, 70, BLACK);

            DrawRectangle(870, 430, 60, 70, BLACK);

            // drapeau
            DrawTexture(porte, 480, 500, WHITE);
        }

        // BLOC DROITE
        {
            DrawRectangle(1150, 550, 200, 400, GRAY);

            {
                DrawRectangle(1200, 650, 50, 50, RAYWHITE);
                DrawRectangle(1252, 650, 50, 50, RAYWHITE);
                DrawRectangle(1200, 702, 50, 50, RAYWHITE);
                DrawRectangle(1252, 702, 50, 50, RAYWHITE);
            }

            //--
            DrawRectangle(925, 250, 250, 100, BLACK);

            DrawRectangle(950, 350, 200, 600, RAYWHITE);

            {
                DrawRectangle(1000, 400, 50, 50, BLACK);
                DrawRectangle(1052, 400, 50, 50, BLACK);
                DrawRectangle(1000, 452, 50, 50, BLACK);
                DrawRectangle(1052, 452, 50, 50, BLACK);
            }

            //--
            DrawRectangle(1125, 500, 250, 70, BLACK);

            DrawRectangle(1125, 430, 70, 70, RED);

            DrawRectangle(1215, 430, 70, 70, RED);

            DrawRectangle(1305, 430, 70, 70, RED);

            // drapeau
            DrawTexture(texture, 1045, 80, WHITE);

            DrawTriangle(CLITERAL(Vector2){1050, 140}, CLITERAL(Vector2){925, 250}, CLITERAL(Vector2){1175, 250}, BLACK);
            // gauche //haut //droite
        }

        DrawRectangle(0, 950, 1400, 100, GREEN);

        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadTexture(porte);
    CloseWindow();
}