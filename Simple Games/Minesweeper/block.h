#ifndef BLOCK_H
#define BLOCK_H

#include "enums.h"
#include "settings.h"

class Block
{
    public:
        blockState state;

    private:
        int xCoord;
        int yCoord;
        bool isBomb;
        int bombsAround;
        Block *blocksAround;
        Settings *settings;

    public:
        Block(int x, int y, bool bomb, Settings *toSet);
        ~Block();
        bool GetIsBomb();
        void DrawBlock();
        void ClickBlock();
        void FlagBlock();
    
    private:
        void HiddenBlock();
        void RevealedBlock();
        void FlaggedBlock();

};

inline Block::Block(int x, int y, bool bomb, Settings *toSet)
{
    state = hidden;
    xCoord = x;
    yCoord = y;
    isBomb = bomb;
    settings = toSet;
    if (!bomb)
    {
        // check blocks around
    }
}

inline Block::~Block()
{
    delete (blocksAround);
}

inline bool Block::GetIsBomb()
{
    return isBomb;
}

#endif