#include "raylib.h"
#include "settings.h"
#include "game.h"

void Game::Play()
{
    InitWindow(settings->xSize, settings->ySize, "Minesweeper");
    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        PaintBackground();
    }
}

void Game::PaintBackground()
{
    BeginDrawing();
    ClearBackground(Color{191,179,204,255});
    EndDrawing();
}