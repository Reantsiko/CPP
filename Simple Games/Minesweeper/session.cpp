#include <iostream>

#include "session.h"
#include "math.h"
Session::Session(int rows, int columns, int blockSize, int bAmount)
{
    std::srand(time(0));
    this->rows = rows;
    this->columns = columns;
    this->bombAmount = bAmount;
    block = new Block**[columns]();
    for (int i = 0; i < columns; i++)
        block[i] = new Block*[rows];
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            block[c][r] = new Block(25 + ((blockSize + 2) * r), 25 + ((blockSize + 2) * c), blockSize);
    bombs = new Block*[bombAmount];
    for (int i = 0; i < bombAmount; i++)
    {
        int xPos = round((rand() % rows));
        int yPos = round((rand() % columns));
        if (!block[yPos][xPos]->GetIsBomb())
        {
            block[yPos][xPos]->SetBomb();
            bombs[i] = block[yPos][xPos];
        }
        else
            i--;
        std::cout << "isBomb = " << xPos << " " << yPos << std::endl;
    }
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
        {
            if (block[c][r]->GetIsBomb())
                continue;
            int max = 8;
            if (r - 1 < 0 || r + 1 >= rows)
                max -= 3;
            if (c - 1 < 0 || c + 1 >= columns)
                max -= 3;
            if (max == 2)
                max++;
            Block **blocksAround = new Block*[max]();
            int pos = 0;
            int bombs = 0;
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    if ((r + x) < 0 || (r + x) >= rows || (c + y) < 0 || (c + y) >= columns || (x == 0 && y == 0))
                    {
                        continue;
                    }
                    blocksAround[pos] = block[c + y][r + x];
                    bombs += block[c+y][r+x]->GetIsBomb() ? 1 : 0;
                    pos++;
                }
            }
            block[c][r]->SetBlockAround(max, bombs, blocksAround);
        }
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
            block[c][r]->DrawBlock();
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

bool Session::CanPlaceFlag()
{
    return (flagsPlaced < bombAmount);
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