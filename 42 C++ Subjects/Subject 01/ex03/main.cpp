#include "ZombieHorde.hpp"

int main()
{
    ZombieHorde* horde = new ZombieHorde();
    horde->createHorde(7);
    horde->announce();
    delete(horde);
    return 0;
}