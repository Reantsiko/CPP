#ifndef PHONEOBJECT_H
#define PHONEOBJECT_H

#include <iostream>

class PhoneObject
{
    public:
        void PrintColumns(int index);
        void PrintInfo();
        bool IsFilled();
    
    private:
        std::string PrepForColumn(std::string toModify);

    public:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phone;
        std::string darkestSecret;
};

#endif

inline void PhoneObject::PrintInfo()
{
    if (!IsFilled())
    {
        std::cout << "No input for this index\n";
        return;
    }
    std::cout   << "First name: " << firstName << '\n' \
                << "Last name: " << lastName << '\n' \
                << "Nickname: " << nickname << '\n' \
                << "Phone: " << phone << '\n' \
                << "Darkest Secret: " << darkestSecret << '\n';
}

inline std::string PhoneObject::PrepForColumn(std::string toModify)
{
    std::string modified;
    size_t wordLen = toModify.length();
    if (wordLen == 10)
        return toModify;
    if (wordLen > 10)
    {
        modified = toModify.substr(0, 10);
        modified[9] = '.';
    }
    else
    {
        modified = toModify.append(" ", 10 - wordLen);
    }
    return modified;
}

inline void PhoneObject::PrintColumns(int index)
{
    std::cout   << PrepForColumn(std::to_string(index)) << '|' \
                << PrepForColumn(firstName) << '|' \
                << PrepForColumn(lastName) << '|' \
                << PrepForColumn(nickname) << '\n';
}

inline bool PhoneObject::IsFilled()
{
    return (!firstName.empty() &&
            !lastName.empty() &&
            !nickname.empty() &&
            !phone.empty() &&
            !darkestSecret.empty());
}