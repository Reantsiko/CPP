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
        int blocksAroundCount = 0;
        Block **blocksAround = nullptr;
        int blockSize;

    public:
        Block();
        Block(int x, int y, bool bomb, int bSize);
        ~Block();
        bool GetIsBomb();
        void SetBlockAround(int max, Block **toSet);
        int GetBomsAround();
        void DrawBorders();
        void DrawBlock();
        void RevealNeighbouringBlocks();
        void FlagBlock();
    
    private:
        void HiddenBlock();
        void RevealedBlock();
        void FlaggedBlock();

};

inline void Block::SetBlockAround(int max, Block **toSet)
{
    blocksAroundCount = max;
    blocksAround = toSet;
}

inline int Block::GetBomsAround()
{
    return bombsAround;
}

inline Block::Block(){}

inline bool Block::GetIsBomb()
{
    return isBomb;
}

#endif