#include "Fixed.hpp"
#include <iostream>

int Fixed::bits = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->number = fixed.getRawBits();
}

Fixed& Fixed::operator=(Fixed &fixed) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}


void Fixed::setRawBits(int rawBits){
	this->number = rawBits;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->number;
}