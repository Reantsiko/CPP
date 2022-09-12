#include <iostream>

#include "session.h"
#include "math.h"
Session::Session(int rows, int columns, int blockSize)
{
    std::srand(time(0));
    this->rows = rows;
    this->columns = columns;
    block = new Block**[columns]();
    for (int i = 0; i < columns; i++)
        block[i] = new Block*[rows];
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            block[r][c] = new Block(50 + ((blockSize + 2) * r), 50 + ((blockSize + 2) * c), blockSize);
    for (int i = 0; i < 10; i++)
    {
        int xPos = round((rand() % rows));
        int yPos = round((rand() % columns));
        block[xPos][yPos]->SetBomb();
        std::cout << "isBomb = " << xPos << " " << yPos << std::endl;
    }
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
        {
            int max = 8;
            if (r - 1 < 0 || r + 1 >= rows)
                max -= 3;
            if (c - 1 < 0 || c + 1 >= columns)
                max -= 3;
            if (max == 2)
                max++;
            Block **blocksAround = new Block*[max]();
            int pos = 0;
            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    if ((r + x) < 0 || (r + x) >= rows || (c + y) < 0 || (c + y) >= columns || (x == 0 && y == 0))
                    {
                        continue;
                    }
                    blocksAround[pos] = block[r + x][c + y];
                    pos++;
                }
            }
            block[r][c]->SetBlockAround(max, blocksAround);
        }
}

Session::~Session()
{
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            delete(block[r][c]);
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
            block[r][c]->DrawBlock();
}