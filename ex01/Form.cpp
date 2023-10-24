#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


Form::Form(){
	this->name = "";
	this->signedd = false;
	this->gradeToExecute = 150;
	this->gradeToSign = 150;
}
Form::Form(const Form& oth){
	*this = oth;
}
Form::~Form(){}
Form& Form::operator=(const Form& oth){
	this->name = oth.name;
	this->signedd = oth.signedd;
	this->gradeToSign = oth.gradeToSign;
	this->gradeToExecute = oth.gradeToExecute;
	return *this;
}

Form::Form(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute){
	this->name = name;
	this->gradeToSign = requiredGradeToSign;
	this->gradeToExecute = requiredGradeToExecute;
	this->signedd = false;
}

const std::string& Form::getName() const {
	return this->name;
}

const bool Form::isSigned() const{
	return this->signedd;
}

const int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

const int Form::getGradeToSign() const {
	return this->gradeToSign;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &message): message(message.c_str()) {}
const char* Form::GradeTooHighException::what() const throw() {
    return message;
}

Form::GradeTooLowException::GradeTooLowException(const std::string &message): message(message.c_str()){}

const char* Form::GradeTooLowException::what() const throw() {
    return message;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
	
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->signedd = true;
	else
		throw GradeTooLowException("Bureaucrat has too low grade to sign it");
}

std::ostream& operator<<(std::ostream &os, const Form& form){
	os << "Name: " << form.getName() << std::endl;
	os << "Signed: " << form.isSigned()  << std::endl;
	os << "Grade required to sign: " << form.getGradeToSign() << std::endl;
	os << "Grade required to execute: " << form.getGradeToExecute() << std::endl;
	return os;
}