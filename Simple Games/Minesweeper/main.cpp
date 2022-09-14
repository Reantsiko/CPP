#include "game.h"
int main()
{
    Game *game = new Game(15, 5, 16, 15);
    game->Play();
    delete(game);
    return 0;
}