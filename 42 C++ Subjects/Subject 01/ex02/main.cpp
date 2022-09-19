#include "ZombieEvent.hpp"

int main()
{
    ZombieEvent event;
    event.setZombieType("Hunter");
    Zombie* myZombie = event.newZombie("Somebody");
    myZombie->announce();
    event.setZombieType("Wanderer");
    Zombie* randomZombie = event.randomChump();
    randomZombie->announce();
    delete(randomZombie);
    delete(myZombie);
    return 0;
}