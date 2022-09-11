#include "raylib.h"
#include "settings.h"
#include "game.h"
#include <iostream>

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
    }
}

void Game::PaintBackground()
{
    BeginDrawing();
    ClearBackground(Color{191,179,204,255});
    EndDrawing();
}