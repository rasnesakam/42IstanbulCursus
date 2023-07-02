#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"){
	std::cout << "Created new Cat!" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat){}

Cat::~Cat(){
	std::cout << "Cat is being destroy." << std::endl;
}

Cat& Cat::operator=(const Cat& cat){
	this->type = cat.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MEEEOOOOOOWWWWW" << std::endl;
}