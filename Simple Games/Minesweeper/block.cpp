#include "raylib.h"
#include "settings.h"
#include <string>
#include <iostream>
#include "block.h"

// PUBLIC

Block::Block(int x, int y, int bSize)
{
    state = hidden;
    xCoord = x;
    yCoord = y;
    blockSize = bSize;
    bombsAround = 0;
}

Block::~Block()
{
    if (blocksAround != nullptr)
        delete (blocksAround);
}

void Block::DrawBlock()
{
    DrawBorders();
    
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

void Block::RevealBlock()
{
    state = revealed;
    if (bombsAround == 0)
        RevealNeighbouringBlocks();
}

void Block::RevealNeighbouringBlocks()
{
    if (blocksAround != nullptr && bombsAround == 0)
    {
        for (int i = 0; i < blocksAroundCount; i++)
        {
            if (blocksAround[i]->state != revealed)
            {
                blocksAround[i]->state = revealed;
                if (blocksAround[i]->bombsAround == 0)
                    blocksAround[i]->RevealNeighbouringBlocks();
            }
        }
    }
    else
        std::cout << "Blocksaround is null\n";
}

void Block::FlagBlock()
{
    for (int i = 0; i < blockSize; i++)
        DrawLine(xCoord, yCoord + i, xCoord + blockSize, yCoord + i, LIGHTGRAY);
    DrawText("F", xCoord, yCoord, blockSize / 2, BLUE);
}

// PRIVATE

void Block::DrawBorders()
{
    DrawLine(xCoord - 1, yCoord - 1, xCoord - 1, yCoord + blockSize + 1, LIGHTGRAY); // left
    DrawLine(xCoord + blockSize+ 1, yCoord - 1, xCoord + blockSize+ 1, yCoord + blockSize + 1, LIGHTGRAY); // right
    DrawLine(xCoord - 1, yCoord - 1, xCoord + blockSize + 1, yCoord - 1, LIGHTGRAY); // top
    DrawLine(xCoord - 1, yCoord + blockSize + 1, xCoord + blockSize + 1, yCoord + blockSize + 1, LIGHTGRAY); // bottom
}

void Block::HiddenBlock()
{
    DrawRectangle(xCoord, yCoord, blockSize, blockSize, GRAY);
}

void Block::RevealedBlock()
{
    DrawRectangle(xCoord, yCoord, blockSize, blockSize, LIGHTGRAY);
    // for (int i = 0; i < blockSize; i++)
    //     DrawLine(xCoord, yCoord + i, xCoord + blockSize, yCoord + i, );
    if (isBomb == false && bombsAround == 0) return;
    if (isBomb)
    {
        DrawText("B", xCoord, yCoord, blockSize / 2, RED);
        return;
    }
    char* text = new char(2);
    text[0] = bombsAround + '0';
    text[1] = '\0';
    DrawText(text, xCoord, yCoord, blockSize, BLUE);
}

void Block::FlaggedBlock()
{
    DrawRectangle(xCoord, yCoord, blockSize, blockSize, LIGHTGRAY);
    DrawText("F", xCoord, yCoord, blockSize / 2, RED);
}