#include "raylib.h"
#include "settings.h"
#include <string>
#include <iostream>
#include "block.h"
#include "session.h"

//
// PUBLIC
//

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

bool Block::RevealBlock()
{
    state = revealed;
    if (isBomb)
    {
        return true;
    }
    if (bombsAround == 0)
        RevealNeighbouringBlocks();
    return false;
}

bool Block::FlagBlock(bool canPlace)
{
    if (state == flagged)
    {
        state = hidden;
        return false;
    }
    if (state == hidden && canPlace)
    {
        state = flagged;
        return true;
    }
    return false;
}

void Block::DrawBorders()
{
    DrawLine(xCoord - 1, yCoord - 1, xCoord - 1, yCoord + blockSize + 1, LIGHTGRAY); // left
    DrawLine(xCoord + blockSize+ 1, yCoord - 1, xCoord + blockSize+ 1, yCoord + blockSize + 1, LIGHTGRAY); // right
    DrawLine(xCoord - 1, yCoord - 1, xCoord + blockSize + 1, yCoord - 1, LIGHTGRAY); // top
    DrawLine(xCoord - 1, yCoord + blockSize + 1, xCoord + blockSize + 1, yCoord + blockSize + 1, LIGHTGRAY); // bottom
}

//
// PRIVATE
//

void Block::HiddenBlock()
{
    DrawRectangle(xCoord, yCoord, blockSize, blockSize, GRAY);
}

void Block::RevealedBlock()
{
    DrawRectangle(xCoord, yCoord, blockSize, blockSize, LIGHTGRAY);
    if (isBomb == false && bombsAround == 0) return;
    if (isBomb)
    {
        DrawText("B", xCoord + blockSize / 4, yCoord + blockSize / 4, blockSize / 2, RED);
        return;
    }
    char* text = new char(2);
    text[0] = bombsAround + '0';
    text[1] = '\0';
    DrawText(text, xCoord + blockSize / 4, yCoord + blockSize / 4, blockSize / 2, BLUE);
}

void Block::FlaggedBlock()
{
    HiddenBlock();
    DrawText("F", xCoord + blockSize / 4, yCoord + blockSize / 4, blockSize / 2, RED);
}

void Block::RevealNeighbouringBlocks()
{
    if (blocksAround != nullptr && bombsAround == 0)
    {
        for (int i = 0; i < blocksAroundCount; i++)
        {
            if (blocksAround[i]->state != revealed && blocksAround[i]->state != flagged && !blocksAround[i]->GetIsBomb())
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