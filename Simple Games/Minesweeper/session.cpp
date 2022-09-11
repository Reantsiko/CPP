#include <iostream>

#include "session.h"

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