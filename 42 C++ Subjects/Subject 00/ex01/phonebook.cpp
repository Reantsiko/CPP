#include <iostream>
#include <string>
#include "phonebook.hpp"

bool PhoneBook::ParseCommand(std::string input)
{
    if (input.compare("EXIT") == 0)
        return false;
    if (input.compare("ADD") == 0)
        Add();
    if (input.compare("SEARCH") == 0)
        Search();
    return true;
}

void PhoneBook::Add()
{
    InputPhone();
    IncreasePosition();
}

void PhoneBook::Search()
{
    int position;
    std::string input;
    if (!PrintSearch())
        return;
    std::cout << "Input an index number\n";
    std::cin >> input;
    position = stoi(input);
    if (position >= 8 || position <= -1)
    {
        std::cout << "Invalid input, number has to be between 0 and 7\n";
        return;
    }
    phoneBook[position].PrintInfo();
}

void PhoneBook::InputPhone()
{
    std::cout << "Input First Name:\n";
    std::cin >> phoneBook[GetPosition()].firstName;
    std::cout << "Input Last Name:\n";
    std::cin >> phoneBook[GetPosition()].lastName;
    std::cout << "Input Nickname:\n";
    std::cin >> phoneBook[GetPosition()].nickname;
    std::cout << "Input Phone:\n";
    std::cin >> phoneBook[GetPosition()].phone;
    std::cout << "Input Darkest Secret: ";
    std::cin >> phoneBook[GetPosition()].darkestSecret;
}

bool PhoneBook::PrintSearch()
{
    size_t index = 0;
    size_t len = GetLength();
    while (index < len)
    {
        if (!phoneBook[index].IsFilled())
            break;
        phoneBook[index].PrintColumns(index);
        index++;
    }
    if (index == 0 && !phoneBook[0].IsFilled())
    {
        std::cout << "Phonebook is empty!\n";
        return false;
    }
    return true;
}