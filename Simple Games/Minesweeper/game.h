#ifndef GAME_H
#define GAME_H

#include "settings.h"

class Game
{
    public:
        Settings *settings;

    public:
        Game();
        ~Game();
        void Play();
    private:
        void PaintBackground();
};

inline Game::Game()
{

}

inline Game::~Game()
{
    delete(settings);
}

#endif