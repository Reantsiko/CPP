#include "raylib.h"
#include "settings.h"
#include "game.h"
#include <iostream>

Game::Game(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    this->settings = new Settings(250, 300, 15);
    block = new Block**[columns]();
    for (int i = 0; i < 5; i++)
        block[i] = new Block*[rows];
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            block[r][c] = new Block(50 + ((settings->blockSize + 2) * r), 50 + ((settings->blockSize + 2) * c), false, settings->blockSize);
}

Game::~Game()
{
    delete(settings);
}

void Game::Play()
{
    InitWindow(settings->xSize, settings->ySize, "Minesweeper");
    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        PaintBackground();
        PaintBlocks();
    }
}

void Game::PaintBackground()
{
    BeginDrawing();
    ClearBackground(Color{191,179,204,255});
    EndDrawing();
}

void Game::PaintBlocks()
{
    if (block == nullptr)
    {
        std::cout << "Block is null\n";
        return;
    }
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            block[r][c]->DrawBlock();
}