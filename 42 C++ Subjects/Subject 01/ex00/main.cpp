#include "Pony.hpp"

Pony *ponyOnTheHeap(std::string name, int age, int speed)
{
    Pony *pony = new Pony(name, age, speed);
    return pony;
}

Pony ponyOnTheStack(std::string name, int age, int speed)
{
    Pony pony = Pony(name, age, speed);
    return pony;
}

int main()
{
    Pony *heapPony = ponyOnTheHeap("Heapy", 5, 100);
    Pony stackPony = ponyOnTheStack("Stacky", 1, 500);

    heapPony->PrintPonyInfo();
    stackPony.PrintPonyInfo();

    delete(heapPony);
    return 0;
}