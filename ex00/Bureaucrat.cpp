#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat(){
	this->name = "undefined";
	this->grade = 150;
}
Bureaucrat::Bureaucrat(const std::string &name, int grade){
	this->name = name;
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat) : name(Bureaucrat.name), grade(Bureaucrat.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& Bureaucrat){
	this->grade = Bureaucrat.grade;
	this->name = Bureaucrat.name;
	return *this;
}

const std::string& Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException("Eyo, grade is too high man");
    if (grade > 150)
        throw GradeTooLowException("Eyo, grade is too low man");
    this->grade = grade;
}

void Bureaucrat::incGrade(){
	this->setGrade(this->getGrade() + 1);
}
void Bureaucrat::decGrade(){
	this->setGrade(this->getGrade() - 1);	
}


Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message): message(message.c_str()) {}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return message;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message): message(message.c_str()){}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return message;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &Bureaucrat){
	os << Bureaucrat.getName();
	os << ", Bureaucrat grade ";
	os << Bureaucrat.getGrade();
	return os;
}