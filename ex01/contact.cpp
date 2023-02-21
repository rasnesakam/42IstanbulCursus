#include "contact.hpp"

Contact::Contact(){
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->darkestSecret = "";
    this->phoneNumber = "";
}

Contact::Contact(std::string firstName,
            std::string lastName,
            std::string nickname,
            std::string darkestSecret,
            std::string phoneNumber){

    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->darkestSecret = darkestSecret;
    this->phoneNumber = phoneNumber;
}

std::string Contact::getNickname(){
    return this->nickname;
}

std::string Contact::getFirstName(){
    return this->firstName;
}

std::string Contact::getLastName(){
    return this->lastName;
}

std::string Contact::getDarkestSecret(){
    return this->darkestSecret;
}

std::string Contact::getPhoneNumber(){
    return this->phoneNumber;
}
