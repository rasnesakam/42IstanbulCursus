#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(){
	this->type = "undefined";
}

WrongAnimal::WrongAnimal(const std::string &type){
	this->type = type;
	std::cout << "WrongAnimal " << this->type <<  " occured in habitat" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal " << this->type <<  " is vanished into nonexistance" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal){
	*this = wrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrongAnimal){
	this->type = wrongAnimal.type;
	return *this;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal making sound that you never expected" << std::endl;
}

const std::string& WrongAnimal::getType() const{
	return this->type;
}