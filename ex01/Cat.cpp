#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"){
	this->brain = new Brain;
	std::cout << "Created new Cat!" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat){
	this->brain = new Brain;
}

Cat::~Cat(){
	std::cout << "Cat is being destroy." << std::endl;
	delete this->brain;
}

Cat& Cat::operator=(const Cat& cat){
	this->brain = cat.brain;
	this->type = cat.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MEEEOOOOOOWWWWW" << std::endl;
}

Brain* Cat::getBrain(){
	return this->brain;
}