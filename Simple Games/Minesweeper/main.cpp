#include "game.h"
int main()
{
    Game *game = new Game();
    game->settings = new Settings(250, 300);
    game->Play();
    delete(game);
    return 0;
}