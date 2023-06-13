#include "Fixed.hpp"
#include <cmath>

const int Fixed::bits = 8;

Fixed::Fixed(){
	this->number = 0;
}

Fixed::Fixed(int number) {
	this->number = number * 1 << this->bits;
}

Fixed::Fixed(float number){
	float sum = 0.5;
	if (number < 0)
		sum = -0.5;
	this->number = (int) roundf((number * (double)(1 << this->bits)) +sum);
}

Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed &fixed) {
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
	this->setRawBits(fixed.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed fixed) {
	os << fixed.toFloat() ;
	return os;
}


// Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs){
	Fixed tmp;
	tmp.setRawBits(this->number + rhs.getRawBits());
	return tmp;
}
Fixed Fixed::operator-(const Fixed& rhs){
	Fixed tmp;
	tmp.setRawBits(this->number - rhs.getRawBits());
	return tmp;
}
Fixed Fixed::operator*(const Fixed& rhs){
	Fixed tmp;
	tmp.setRawBits(this->number * rhs.getRawBits() >> this->bits);
	return tmp;
}
Fixed Fixed::operator/(const Fixed& rhs){
	Fixed tmp;
	tmp.setRawBits((this->number << this->bits) / rhs.getRawBits());
	return tmp;
}

// Increment overloads
//prefix
Fixed& Fixed::operator++(){
	this->setRawBits(this->number + 1);
	return *this;
}
Fixed Fixed::operator++(int){
	Fixed temp(*this);
	++(*this);
	return temp;
}
Fixed& Fixed::operator--(){
	this->setRawBits(this->number - 1);
	return *this;
}
Fixed Fixed::operator--( int){
	Fixed temp(*this);
	--(*this);
	return temp;
}

// Conditional operators
inline bool Fixed::operator>(const Fixed& rhs) const
{
	return this->number > rhs.getRawBits();
}
inline bool Fixed::operator>=(const Fixed& rhs) const
{
	return this->number >= rhs.getRawBits();
}
inline bool Fixed::operator<(const Fixed& rhs) const
{
	return this->number < rhs.getRawBits();
}
inline bool Fixed::operator<=(const Fixed& rhs) const
{
	return this->number <= rhs.getRawBits();
}
inline bool Fixed::operator==(const Fixed& rhs) const
{
	return this->number == rhs.getRawBits();
}
inline bool Fixed::operator!=(const Fixed& rhs) const
{
	return this->number != rhs.getRawBits();
}

// Min and Max funcs
const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return a;
	return b;
}