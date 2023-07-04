#include "Dog.hpp"
#include <iostream>

Dog::Dog():Animal("Dog"){
	this->brain = new Brain;
	std::cout << "New Dog Created!" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog is being destroy." << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &dog): Animal(dog.type){
	this->brain = new Brain;
	std::cout << "New Dog Copied!" << std::endl;
}

Dog& Dog::operator=(const Dog& dog){
	this->brain = dog.brain;
	this->type = dog.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "AĞLASAM DUYAR MISIN SESİMİ MISRALARIMDA, HAV, HAV, HAV" << std::endl;
}

Brain* Dog::getBrain(){
	return this->brain;
}