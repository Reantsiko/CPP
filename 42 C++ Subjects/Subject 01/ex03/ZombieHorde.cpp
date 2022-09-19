#include "ZombieHorde.hpp"

#include <time.h>
#include <iostream>

void ZombieHorde::createHorde(int amount)
{
    if (amount <= 0)
    {
        std::cout << "The horde was a lie\n";
        return;
    }
    horde = new Zombie*[amount];
    for (int i = 0; i < amount; i++)
    {
        horde[i] = new Zombie(nameGenerator(), "Hoarder");
    }
}

void ZombieHorde::announce()
{
    int i = 0;
    while (horde[i] != nullptr)
    {
        horde[i]->announce();
        i++;
    }
}

ZombieHorde::ZombieHorde()
{
    srand(time(NULL));
}

ZombieHorde::~ZombieHorde()
{
    std::cout << "The horde has been destroyed";
    delete[] horde;
}

std::string ZombieHorde::nameGenerator()
{
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    int nameLength = rand() % 10 + 3;
    int i = 0;
    std::string name = std::string(nameLength + 1, '\0');
    while (i < nameLength)
    {
        name[i] = letters[rand() % 26];
        i++;
    }
    name[0] = toupper(name[0]);
    return name;
}