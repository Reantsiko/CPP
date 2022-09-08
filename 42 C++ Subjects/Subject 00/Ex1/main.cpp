#include <iostream>
#include "phonebook.h"
int main()
{
    PhoneBook phonebook;
    while (true)
    {
        std::cout << "Input Command\n1) ADD\n2) SEARCH\n3) EXIT\n";
        std::string input;
        std::cin >> input;
        if (phonebook.ParseCommand(input) == false)
            break;
    }
    return 0;
}