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
        int GetRows();
        int GetColumns();
};

inline int Session::GetRows()
{
    return rows;
}

inline int Session::GetColumns()
{
    return columns;
}

#endif