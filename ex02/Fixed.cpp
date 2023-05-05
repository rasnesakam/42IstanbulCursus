#include "Fixed.hpp"
#include <cmath>

int Fixed::bits = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(int number) {
	std::cout << "Int constructor called" << std::endl;
	this->number = number * 1 << this->bits;
}

Fixed::Fixed(float number){
	std::cout << "Float constructor called" << std::endl;
	float sum = 0.5;
	if (number < 0)
		sum = -0.5;
	this->number = (int) roundf((number * (double)(1 << this->bits)) +sum);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->number = fixed.getRawBits();
}

void Fixed::setRawBits(int rawBits){
	this->number = rawBits;
}

int Fixed::getRawBits(void) const {
	return this->number;
}

int Fixed::toInt(void) const{
	return this->getRawBits() / (1 << this->bits);
}


float Fixed::toFloat(void) const{
	return (float) this->getRawBits() / (float) (1 << this->bits);
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat() ;
	return os;
}