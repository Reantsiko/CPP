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
        bool isBomb = false;
        int bombsAround = 0;
        int blocksAroundCount = 0;
        Block **blocksAround = nullptr;
        int blockSize;

    public:
        Block(int x, int y, int bSize);
        ~Block();
        void DrawBlock();
        bool RevealBlock();
        bool FlagBlock(bool canPlace);
        bool GetIsBomb();
        void SetBlockAround(int max, Block **toSet);
        int GetBomsAround();
        void DrawBorders();
        void SetBomb();
        void IncreaseBombCount();
    
    private:
        void HiddenBlock();
        void RevealedBlock();
        void FlaggedBlock();
        void RevealNeighbouringBlocks();

};

inline void Block::SetBlockAround(int max, Block **toSet)
{
    blocksAroundCount = max;
    blocksAround = toSet;
}

inline void Block::IncreaseBombCount()
{
    bombsAround++;
}

inline void Block::SetBomb()
{
    isBomb = true;
}

inline int Block::GetBomsAround()
{
    return bombsAround;
}

inline bool Block::GetIsBomb()
{
    return isBomb;
}

#endif