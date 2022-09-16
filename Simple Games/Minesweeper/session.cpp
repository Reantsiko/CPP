#include <iostream>

#include "session.h"
#include "math.h"

//
//  PUBLIC
//

Session::Session(int rows, int columns, int blockSize, int bAmount)
{
    std::srand(time(0));
    this->rows = rows;
    this->columns = columns;
    this->bombAmount = bAmount;
    InitBlocks(blockSize);
    InitBombs();
    LinkBlocks();
}

Session::~Session()
{
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            delete(block[c][r]);
    delete(block);
}

void Session::PaintBlocks()
{
    if (block == nullptr)
    {
        std::cout << "Block is null\n";
        return;
    }
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
        {
            // std::cout << "Drawing Block With Coords X: " << r << " Coords Y: " << c << std::endl;
            block[c][r]->DrawBlock();
        }
}

bool Session::RevealBlock(int xCoord, int yCoord)
{
    if (block[yCoord][xCoord] == nullptr)
        return false;
    if (block[yCoord][xCoord]->state == hidden)
        return block[yCoord][xCoord]->RevealBlock();
    return false;
}

void Session::PlaceFlag(int xCoord, int yCoord)
{
    if (block[yCoord][xCoord] == nullptr)
        return;
    if (block[yCoord][xCoord]->state == flagged)
    {
        block[yCoord][xCoord]->state = hidden;
        flagsPlaced--;
        return;
    }
    if (block[yCoord][xCoord]->state == hidden && CanPlaceFlag())
    {
        block[yCoord][xCoord]->state = flagged;
        flagsPlaced++;
        std::cout << "flagsPlaced = " << flagsPlaced << " bombAmount = " << bombAmount << std::endl;
    }
}

void Session::RevealBombs()
{
    if (bombs == nullptr)
        return;
    for (int i = 0; i < bombAmount; i++)
    {
        if (bombs[i] != nullptr)
            bombs[i]->RevealBlock();
    }
}
//
//  PRIVATE
//

bool Session::IsOutsideBounds(int xPos, int yPos, int row, int column)
{
    return ((row + xPos) < 0 || 
            (row + xPos) >= rows || 
            (column + yPos) < 0 || 
            (column + yPos) >= columns || 
            (xPos == 0 && yPos == 0));
}

void Session::InitBlocks(int blockSize)
{
    block = new Block**[columns]();
    for (int i = 0; i < columns; i++)
        block[i] = new Block*[rows];
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            block[c][r] = new Block(25 + ((blockSize + 2) * r), 25 + ((blockSize + 2) * c), blockSize);
}

void Session::InitBombs()
{
    bombs = new Block*[bombAmount];
    for (int i = 0; i < bombAmount; i++)
    {
        int xPos = round((rand() % rows));
        int yPos = round((rand() % columns));
        if (!block[yPos][xPos]->GetIsBomb())
        {
            block[yPos][xPos]->SetBomb();
            bombs[i] = block[yPos][xPos];
            IncreaseBombCounter(xPos, yPos);
        }
        else
            i--;
        std::cout << "isBomb = " << xPos << " " << yPos << std::endl;
    }
}

void Session::IncreaseBombCounter(int xPos, int yPos)
{
    for (int c = -1; c < 2; c++)
        for (int r = -1; r < 2; r++)
        {
            if (IsOutsideBounds(xPos, yPos, r, c))
                continue;
            block[yPos + c][xPos + r]->IncreaseBombCount();
        }
}

void Session::LinkBlocks()
{
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
        {
            int max = 8 - ((r - 1 < 0 || r + 1 >= rows) ? 3 : 0)
                        - ((c - 1 < 0 || c + 1 >= columns) ? 3 : 0);
            if (max == 2)
                max++;
            Block **blocksAround = new Block*[max]();
            int pos = 0;
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    if (IsOutsideBounds(x, y, r, c))
                        continue;
                    blocksAround[pos] = block[c + y][r + x];
                    pos++;
                }
            }
            block[c][r]->SetBlockAround(max, blocksAround);
        }
}

bool Session::CanPlaceFlag()
{
    return (flagsPlaced < bombAmount);
}