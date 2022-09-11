#ifndef GAME_H
#define GAME_H

#include "settings.h"
#include "block.h"
class Game
{
    public:
        Settings *settings;
        Block ***block;

    private:
        int rows;
        int columns;

    public:
        Game(int rows, int columns);
        ~Game();
        void Play();
    private:
        void PaintBackground();
        void PaintBlocks();
};

#endif