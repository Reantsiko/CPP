#include "game.h"
int main()
{
    Game* game = new Game(600, 300);
    game->GameLoop();
    return 0;
}