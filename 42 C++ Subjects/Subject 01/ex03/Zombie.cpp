#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name, std::string type)
{
    this->_name = name;
    this->_type = type;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " got his head bashed in!\n";
}

void Zombie::announce()
{
    std::cout << this->_name << " (" << this->_type << ") Braiiiiinnnsssssss.....\n";
}