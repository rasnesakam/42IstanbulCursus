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
        throw GradeTooHighException("Eyo, grade is too low man");
    if (grade > 150)
        throw GradeTooLowException("Eyo, grade is too high man");
    this->grade = grade;
}

void Bureucrat::incGrade(){
	this->setGrade(this->getGrade() + 1);
}
void Bureucrat::decGrade(){
	this->setGrade(this->getGrade() - 1);
}


Bureucrat::GradeTooHighException::GradeTooHighException(const std::string &message): message(message.c_str()) {}
const char* Bureucrat::GradeTooHighException::what() {
    return message;
}

Bureucrat::GradeTooLowException::GradeTooLowException(const std::string &message): message(message.c_str()){}

const char* Bureucrat::GradeTooLowException::what() {
    return message;
}

std::ostream& operator<<(std::ostream &os, const Bureucrat &bureucrat){
	os << bureucrat.getName();
	os << ", bureucrat grade ";
	os << bureucrat.getGrade();
	return os;
}