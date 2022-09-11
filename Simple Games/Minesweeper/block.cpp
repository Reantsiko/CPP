#include "raylib.h"
#include "settings.h"
#include <string>
#include <iostream>
#include "block.h"

// PUBLIC

void Block::DrawBlock()
{
    switch (state)
    {
        case hidden:
            return HiddenBlock();
        case flagged:
            return FlaggedBlock();
        case revealed:
            return RevealedBlock();
    }
}

void Block::ClickBlock()
{
    
}

void Block::FlagBlock()
{
    for (int i = 0; i < yCoord; i++)
        DrawLine(xCoord, yCoord + i, xCoord + settings->blockSize, yCoord + i, LIGHTGRAY);
    DrawText("F", xCoord, yCoord, settings->blockSize / 2, BLUE);
}

// PRIVATE

void Block::HiddenBlock()
{
    for (int i = 0; i < yCoord; i++)
        DrawLine(xCoord, yCoord + i, xCoord + settings->blockSize, yCoord + i, GRAY);
}

void Block::RevealedBlock()
{
    for (int i = 0; i < yCoord; i++)
        DrawLine(xCoord, yCoord + i, xCoord + settings->blockSize, yCoord + i, LIGHTGRAY);
    if (isBomb == false && bombsAround == 0) return;
    if (isBomb)
    {
        DrawText("B", xCoord, yCoord, settings->blockSize / 2, RED);
        return;
    }
    char* text = new char(2);
    text[0] = bombsAround + '0';
    text[1] = '\0';
    DrawText(text, xCoord, yCoord, settings->blockSize / 2, BLUE);
}

void Block::FlaggedBlock()
{
    DrawLine(xCoord, yCoord, xCoord + settings->blockSize, yCoord + settings->blockSize, BLACK);
}