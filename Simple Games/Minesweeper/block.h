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
        int blockSize;

    public:
        Block();
        Block(int x, int y, bool bomb, int bSize);
        ~Block();
        bool GetIsBomb();
        void DrawBorders();
        void DrawBlock();
        void ClickBlock();
        void FlagBlock();
    
    private:
        void HiddenBlock();
        void RevealedBlock();
        void FlaggedBlock();

};

inline Block::Block(){}

inline bool Block::GetIsBomb()
{
    return isBomb;
}

#endif