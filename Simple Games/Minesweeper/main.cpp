#include "game.h"
int main()
{
    Game *game = new Game(3, 6);
    game->Play();
    delete(game);
    return 0;
}