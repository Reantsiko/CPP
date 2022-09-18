#include "game.h"
#include "raylib.h"
#include "snake.h"
#include "candy.h"

Game::Game(int width, int height)
{
    InitWindow(width, height, "Snake");
}

void Game::GameLoop()
{
    Snake *snake = new Snake();
    Candy *candy = new Candy();
    SetTargetFPS(snake->GetSpeed());
    while (!WindowShouldClose())
    {
        PaintBackground();
        snake->SetMoveDir(KeyboardKey(GetKeyPressed()));
        candy->PaintCandy();
        snake->PaintSnake(candy);
    }
}

void Game::PaintBackground()
{
    BeginDrawing();
    ClearBackground(LIGHTGRAY);
    EndDrawing();
}