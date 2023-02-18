#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int index;
    public:
        PhoneBook();
        Contact getContact(int index);
        void addContact(Contact contact);
};

#endif