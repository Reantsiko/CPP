#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
    public:
        ZombieHorde();
        ~ZombieHorde();
        void createHorde(int amount);
        void announce();
    private:
        std::string nameGenerator();
        Zombie** horde;
};

#endif