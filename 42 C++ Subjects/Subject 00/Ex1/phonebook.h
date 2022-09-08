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
        size_t GetLength();
        void IncreasePosition();
        int GetPosition();

    private:
        void InputPhone();
        bool PrintSearch();

    private:
        PhoneObject phoneBook[8];
        int position = 0;
};

#endif

inline PhoneBook::PhoneBook(){}
inline size_t PhoneBook::GetLength() { return std::size(phoneBook); }
inline void PhoneBook::IncreasePosition()
{ 
    position++;
    if (position >= 8)
        position = 0;
}
inline int PhoneBook::GetPosition() { return position; }