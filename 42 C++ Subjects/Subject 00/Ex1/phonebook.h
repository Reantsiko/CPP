#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "phoneobject.h"

class PhoneBook
{
    public:
        PhoneBook();
    public:
        bool ParseCommand(std::string input);
        void Add();
        void Search();
        int GetLength();
        void IncreasePosition();
        int GetPosition();

    private:
        void InputPhone();

    private:
        PhoneObject phoneBook[8];
        int position = 0;
};

#endif

inline PhoneBook::PhoneBook(){}
inline int PhoneBook::GetLength() { return std::size(phoneBook); }
inline void PhoneBook::IncreasePosition()
{ 
    position++;
    if (position >= 8)
        position = 0;
}
inline int PhoneBook::GetPosition() { return position; }