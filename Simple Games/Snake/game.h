#ifndef GAME_H
#define GAME_H

class Game
{
    public:
        Game(int width, int height);
        void GameLoop();
    
    private:
        void PaintBackground();
};

#endif