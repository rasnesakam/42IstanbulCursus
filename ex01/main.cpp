#include <iostream>
#include "phonebook.hpp"



void addContact(PhoneBook *book) {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;

    //TODO: DONT SUPPOR NON ASCII CHARS
    // BUNLAR GETLINE OLACAK
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << std::endl << "Enter last name: ";
    std::getline(std::cin, lastName);
    std::cout << std::endl << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << std::endl << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    std::cout << std::endl << "Enter phone number (Whatever you say, i believe it.): ";
    std::cout << std::endl;
    Contact contact(firstName,lastName,nickname, darkestSecret,5393408356);
    std::cout <<"Added contact: " << std::endl;
    book->addContact(contact);
}

void filter(std::string infos){
    if (infos.length() < 10){
        int len = 0;
        while (len + infos.length() < 10){
            std::cout << " ";
            len++;
        }
        std::cout << infos;
    }
    else {
        int i= 0;
        while (i < 9)
            std::cout << infos[i++];
        std::cout << ".";
    }
}

void printContact(int index, Contact c){
    std::cout << "|" << index + 1 << "|";
    filter(c.getFirstName());
    std::cout << "|";
    filter(c.getLastName());
    std::cout << "|";
    filter(c.getNickname());
    std::cout << "|";
}

void printContactExtra(Contact c){
    if (!c.getFirstName().empty()){
        std::cout << "First name is: " << c.getFirstName() << std::endl;
        std::cout << "Last name is: " << c.getLastName() << std::endl;
        std::cout << "Nickname is: " << c.getNickname() << std::endl;
        std::cout << "Phone Number is: " << c.getPhoneNumber() << std::endl;
        std::cout << "Darkest secret is: " << c.getDarkestSecret() << std::endl;
    }
    else
        std::cout << "There is no such contact. Please try again with another contact." << std::endl;
}

void searchBook(PhoneBook *book) {
    int index = 0;
    while (index < 8 && !book->getContact(index).getFirstName().empty()){
        printContact(index, book->getContact(index));
        std::cout << std::endl;
        index++;
    }
    bool exit = false;
    std::string prompt;
    int iprompt;
    while (!exit) {
        std::cout << "Enter index number to show detailed information (Press '0'(zero) to exit)" << std::endl;
        std::getline(std::cin, prompt);
        iprompt = std::stoi(prompt);
        if (iprompt > 0 && iprompt < 8){
            printContactExtra(book->getContact(iprompt - 1));
        }
        else if (iprompt == 0)
            exit = true;
        else {
            std::cout << "Unknown Contact." << std::endl;
        }
    }
}

int main(){
    PhoneBook book;
    bool exit = false;
    std::string prompt;
    while (!exit) {
        std::cout << "WELCOME TO PHONE BOOK. WHAT DO YOUUU WANT" << std::endl;
        std::getline(std::cin, prompt);
        if (strcmp(prompt.c_str(), "ADD") == 0)
            addContact(&book);
        else if (strcmp(prompt.c_str(), "SEARCH") == 0)
            searchBook(&book);
        else if (strcmp(prompt.c_str(), "EXIT") == 0)
            exit = true;
        else {
            std::cout << "Undefined Command." << std::endl;
        }
    }
    return 0;
}