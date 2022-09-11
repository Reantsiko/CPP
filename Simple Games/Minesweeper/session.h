#ifndef SESSION_H
#define SESSION_H

#include "block.h"

class Session
{
    public:
        Block ***block;

    private:
        int rows;
        int columns;

    public:
        Session(int rows, int columns, int blockSize);
        ~Session();
        void PaintBlocks();
};

inline Session::Session(int rows, int columns, int blockSize)
{
    this->rows = rows;
    this->columns = columns;
    block = new Block**[columns]();
    for (int i = 0; i < columns; i++)
        block[i] = new Block*[rows];
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            block[r][c] = new Block(50 + ((blockSize + 2) * r), 50 + ((blockSize + 2) * c), false, blockSize);
}

inline Session::~Session()
{
    for (int c = 0; c < columns; c++)
        for (int r = 0; r < rows; r++)
            delete(block[r][c]);
    delete(block);
}

#endif