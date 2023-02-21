#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string darkestSecret;
        long phoneNumber;
    public:
        Contact();
        Contact(std::string firstName,
            std::string lastName,
            std::string nickname,
            std::string darkestSecret,
            long phoneNumber);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getDarkestSecret();
        long getPhoneNumber();
};

#endif