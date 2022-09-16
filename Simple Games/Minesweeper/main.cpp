#include "game.h"
int main()
{
    Game *game = new Game(10, 10, 16, 15);
    game->Play();
    delete(game);
    return 0;
}