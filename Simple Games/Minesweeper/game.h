#ifndef GAME_H
#define GAME_H

#include "settings.h"
#include "session.h"
#include "raylib.h"
class Game
{
    public:
        Settings *settings;
        Session *session;
    
    private:
        bool inSession = true;

    public:
        Game(int rows, int columns, int blockSize, int bombAmount);
        ~Game();
        void Play();
        void Click(bool isRightClick);

    private:
        void PaintBackground();
        Vector2 GetBlockCoord();
};

#endif