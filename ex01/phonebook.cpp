#include "phonebook.hpp"


PhoneBook::PhoneBook(){
    this->index = 0;
}

void PhoneBook::addContact(Contact contact){
    this->contacts[this->index] = contact;
    this->index = (this->index + 1) % 8;
}

Contact PhoneBook::getContact(int index){
    Contact contact;
    if (index < 8)
        return this->contacts[index];
    else return contact;

}