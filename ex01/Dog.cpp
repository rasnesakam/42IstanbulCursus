#include "Dog.hpp"
#include <iostream>

Dog::Dog():Animal("Dog"){
	std::cout << "New Dog Created!" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog is being destroy." << std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog.type){}

Dog& Dog::operator=(const Dog& dog){
	this->type = dog.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "AĞLASAM DUYAR MISIN SESİMİ MISRALARIMDA, HAV, HAV, HAV" << std::endl;
}