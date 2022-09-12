#include "raylib.h"
#include "settings.h"
#include "game.h"
#include <iostream>
#include "math.h"
Game::Game()
{
    this->settings = new Settings(250, 300, 15);
    this->session = new Session(6,6, this->settings->blockSize);
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
        if (IsMouseButtonPressed(0))
        {
            Vector2 mousePos = GetMousePosition();
            std::cout << mousePos.x << ' ' << mousePos.y << std::endl;
            mousePos.x = floor((mousePos.x - 50) / 16);
            mousePos.y = floor((mousePos.y - 50) / 16);

            // std::cout << mousePos.x << ' ' << mousePos.y << std::endl;
            if (mousePos.x < session->GetRows() && mousePos.y < session->GetColumns())
            {
                if (session->block[(int)mousePos.x][(int)mousePos.y] != nullptr)
                {
                    std::cout << "Clicked block\n" << mousePos.x << " " << mousePos.y << std::endl;
                    session->block[(int)mousePos.x][(int)mousePos.y]->state = revealed;
                    if (session->block[(int)mousePos.x][(int)mousePos.y]->GetBomsAround() == 0)
                        session->block[(int)mousePos.x][(int)mousePos.y]->RevealNeighbouringBlocks();
                }
            }
        }
    }
}

void Game::PaintBackground()
{
    BeginDrawing();
    ClearBackground(Color{191,179,204,255});
    EndDrawing();
}