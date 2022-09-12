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
        int bombsAround;
        int blocksAroundCount = 0;
        Block **blocksAround = nullptr;
        int blockSize;

    public:
        Block();
        Block(int x, int y, int bSize);
        ~Block();
        bool GetIsBomb();
        void SetBlockAround(int max, int bombs, Block **toSet);
        int GetBomsAround();
        void DrawBorders();
        void DrawBlock();
        void RevealBlock();
        void FlagBlock();
        void SetBomb();
    
    private:
        void HiddenBlock();
        void RevealedBlock();
        void FlaggedBlock();
        void RevealNeighbouringBlocks();

};

inline void Block::SetBlockAround(int max, int bombs, Block **toSet)
{
    blocksAroundCount = max;
    bombsAround = bombs;
    blocksAround = toSet;
}

inline void Block::SetBomb()
{
    isBomb = true;
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