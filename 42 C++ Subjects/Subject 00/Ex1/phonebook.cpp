#include "phonebook.h"

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
    std::cout << "Input an index number:\n";
    std::string input;
    std::cin >> input;
    for (size_t i = 0; i < std::size(input); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            std::cout << "Incorrect input, requires number\n";
            return;
        }
    }
    position = stoi(input) - 1;
    if (position >= 8 || position <= -1)
    {
        std::cout << "Invalid input, number has to be between 1 and 8\n";
        return;
    }
    if (!phoneBook[position].firstName.empty())
        std::cout << phoneBook[position].firstName << "\n" << phoneBook[position].lastName << "\n" << phoneBook[position].nickname << '\n';
    else
        std::cout << "No input on this index\n";
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
    std::cout << "Input Darkest Secret:\n";
    std::cin >> phoneBook[GetPosition()].darkestSecret;
}