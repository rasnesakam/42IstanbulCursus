#include "Bureucrat.hpp"
#include <sstream>

Bureucrat::Bureucrat(){
	this->name = "undefined";
	this->grade = 150;
}
Bureucrat::Bureucrat(const std::string &name, int grade){
	this->name = name;
	this->setGrade(grade);
}

Bureucrat::~Bureucrat(){}

Bureucrat::Bureucrat(const Bureucrat &bureucrat) : name(bureucrat.name), grade(bureucrat.grade) {}

Bureucrat& Bureucrat::operator=(const Bureucrat& bureucrat){
	this->grade = bureucrat.grade;
	this->name = bureucrat.name;
	return *this;
}

const std::string& Bureucrat::getName() const{
	return this->name;
}

const int Bureucrat::getGrade() const{
	return this->grade;
}

void Bureucrat::setGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException("Eyo, grade is too low man"); // Düşük not hatası için
    if (grade > 150)
        throw GradeTooLowException("Eyo, grade is too high man"); // Yüksek not hatası için
    this->grade = grade;
}


Bureucrat::GradeTooHighException::GradeTooHighException(const std::string &message) {
	this->message = message;
}
const char* Bureucrat::GradeTooHighException::what() {
    return message.c_str();
}

Bureucrat::GradeTooLowException::GradeTooLowException(const std::string &message)
	:message(message){
}

const char* Bureucrat::GradeTooLowException::what() {
    return message.c_str();
}

std::ostream& operator<<(std::ostream &os, const Bureucrat &bureucrat){
	os << bureucrat.getName();
	os << ", bureucrat grade ";
	os << bureucrat.getGrade();
	return os;
}