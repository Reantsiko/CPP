#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* brainPointer = &brain;
    std::string& brainReference = brain;

    std::cout << brainPointer << std::endl;
    std::cout << brainReference << std::endl;
    return (0);
}