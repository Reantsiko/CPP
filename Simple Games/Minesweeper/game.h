#ifndef GAME_H
#define GAME_H

#include "settings.h"
#include "session.h"
class Game
{
    public:
        Settings *settings;
        Session *session;

    public:
        Game();
        ~Game();
        void Play();
    private:
        void PaintBackground();
};

#endif