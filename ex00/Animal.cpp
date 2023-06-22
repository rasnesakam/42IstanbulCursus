#include "Animal.hpp"
#include <iostream>

Animal::Animal(){
	this->type = "undefined";
}

Animal::Animal(const std::string &type){
	this->type = type;
	std::cout << "Animal " << this->type <<  " occured in habitat" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal " << this->type <<  " is vanished into nonexistance" << std::endl;
}

Animal::Animal(const Animal &animal){
	*this = animal;
}

Animal& Animal::operator=(const Animal &animal){
	this->type = animal.type;
	return *this;
}

void Animal::makeSound() const{
	std::cout << "Animal making sound that we cannot understand." << std::endl;
}

const std::string& Animal::getType() const{
	return this->type;
}