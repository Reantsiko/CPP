#ifndef SESSION_H
#define SESSION_H

#include "block.h"

class Session
{
    public:
        Block ***block;
        Block **bombs;

    private:
        int rows = 0;
        int columns = 0;
        int bombAmount = 0;
        int flagsPlaced = 0;

    public:
        Session(int rows, int columns, int blockSize, int bAmount);
        ~Session();
        void PaintBlocks();
        int GetRows();
        int GetColumns();
        bool RevealBlock(int xCoord, int yCoord);
        void PlaceFlag(int xCoord, int yCoord);
        void RevealBombs();

    private:
        bool CanPlaceFlag();
};

inline int Session::GetRows()
{
    return rows;
}

inline int Session::GetColumns()
{
    return columns;
}

// inline bool Session::CanPlaceFlag()
// {
//     return flagsPlaced < bombAmount;
// }

#endif