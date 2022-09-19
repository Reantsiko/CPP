#include "ZombieEvent.hpp"

#include <time.h>

void ZombieEvent::setZombieType(std::string type)
{
    _type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    return new Zombie(name, _type);
}

Zombie* ZombieEvent::randomChump()
{
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    int nameLength = rand() % 10 + 3;
    int i = 0;
    std::string name = std::string(nameLength + 1, '\0');
    while (i < nameLength)
    {
        name[i] = letters[rand() % 26];
        i++;
    }
    
    name[0] = toupper(name[0]);
    return newZombie(name);
}