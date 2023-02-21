#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string darkestSecret;
        std::string phoneNumber;
    public:
        Contact();
        Contact(std::string firstName,
            std::string lastName,
            std::string nickname,
            std::string darkestSecret,
            std::string phoneNumber);

        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getDarkestSecret();
        std::string getPhoneNumber();
};

#endif