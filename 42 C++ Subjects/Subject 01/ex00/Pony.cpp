#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string name, int age, int speed)
{
    this->name = name;
    this->age = age;
    this->speed = speed;
    std::cout << "A pony came into existence with the name: " << this->name << '\n';
}

Pony::~Pony()
{
    std::cout << "The pony with name " << this->name << " has run away!\n";
}

void Pony::PrintPonyInfo()
{
    std::string spd;
    if (this->speed < 100)
        spd = "slow";
    if (this->speed >= 100 && this->speed < 300)
        spd = "medium";
    if (this->speed >= 300 && this->speed < 400)
        spd = "fast";
    if (this->speed >= 400)
        spd = "ZOOMIES";
    std::cout << "This pony is " << this->name << " it is " << this->age << "years old\n";
    std::cout << "The pony has a " << spd << " speed!\n";
}