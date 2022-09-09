#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony
{
    public:
        Pony(std::string name, int age, int speed);
        ~Pony();
        void PrintPonyInfo();

    private:
        std::string name;
        int age;
        int speed;

};

#endif