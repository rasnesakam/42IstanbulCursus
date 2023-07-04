#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "Created new WrongCat!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat): WrongAnimal(wrongCat){}

WrongCat::~WrongCat(){
	std::cout << "WrongCat is being destroy." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat){
	this->type = wrongCat.type;
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "WHO LET THE DOGS OUT!! WUPFH WUPFH" << std::endl;
}