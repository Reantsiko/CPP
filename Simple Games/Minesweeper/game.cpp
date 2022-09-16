#include "raylib.h"
#include "settings.h"
#include "game.h"
#include <iostream>
#include "math.h"

//
//  PUBLIC
//

Game::Game(int rows, int columns, int blockSize, int bombAmount)
{
    this->settings = new Settings(50 + (blockSize + 2) * rows, 50 + (blockSize + 2) * columns, blockSize);
    this->session = new Session(rows, columns, blockSize, bombAmount);
}

Game::~Game()
{
    delete(settings);
    if (session != nullptr)
        delete (session);
}

void Game::Play()
{
    InitWindow(settings->xSize, settings->ySize, "Minesweeper");
    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        PaintBackground();
        if (session != nullptr)
            session->PaintBlocks();
        if (inSession)
        {
            if (IsMouseButtonPressed(0))
                Click(false);
            if (IsMouseButtonPressed(1))
                Click(true);
        }
        if (IsKeyPressed(KEY_R))
        {
            std::cout << "RESET!";
            int rows = session->GetRows();
            int columns = session->GetColumns();
            int bombs = session->GetBombAmount();
            delete(session);
            session = new Session(rows, columns, 16, bombs);
            inSession = true;
        }
    }
}

void Game::Click(bool isRightClick)
{
    Vector2 blockCoord = GetBlockCoord();

    if ((int)blockCoord.x < session->GetRows() && (int)blockCoord.y < session->GetColumns())
    {
            std::cout << "Clicked block\n" << blockCoord.x << " " << blockCoord.y << std::endl;
            if (isRightClick)
                session->PlaceFlag(blockCoord.x, blockCoord.y);
            else
            {
                bool isBomb = session->RevealBlock(blockCoord.x, blockCoord.y);
                if (isBomb)
                {
                    session->RevealBombs();
                    inSession = false;
                    std::cout << "BOOOOOOOOOM\n";
                }
            }
    }
}

//
//  PRIVATE
//

void Game::PaintBackground()
{
    BeginDrawing();
    ClearBackground(Color{191,179,204,255});
    EndDrawing();
}

Vector2 Game::GetBlockCoord()
{
    Vector2 mousePos = GetMousePosition();
    std::cout << mousePos.x << ' ' << mousePos.y << std::endl;
    mousePos.x = floor((mousePos.x - 25) / (settings->blockSize + 2));
    mousePos.y = floor((mousePos.y - 25) / (settings->blockSize + 2));
    return mousePos;
}