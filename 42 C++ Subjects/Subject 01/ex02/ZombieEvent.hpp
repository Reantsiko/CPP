#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
    public:
        Zombie* newZombie(std::string name);
        void setZombieType(std::string type);
        Zombie* randomChump();

    private:
        std::string _type;
};

#endif