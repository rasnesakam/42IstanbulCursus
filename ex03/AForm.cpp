#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute){
	this->name = name;
	this->gradeToSign = requiredGradeToSign;
	this->gradeToExecute = requiredGradeToExecute;
	this->signedd = false;
}

const std::string& AForm::getName() const {
	return this->name;
}

const bool AForm::isSigned() const{
	return this->signedd;
}

const int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

const int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &message): message(message.c_str()) {}
const char* AForm::GradeTooHighException::what() {
    return message;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &message): message(message.c_str()){}

const char* AForm::GradeTooLowException::what() {
    return message;
}

AForm::FormNotSignedException::FormNotSignedException(const std::string &message): message(message.c_str()){}

const char* AForm::FormNotSignedException::what() {
    return message;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->signedd = true;
	else
		throw GradeTooLowException("Bureaucrat has too low grade to sign it");
}

AForm::~AForm(){}

std::ostream& operator<<(std::ostream &os, const AForm& aForm){
	os << "Name: " << aForm.getName() << std::endl;
	os << "Signed: " << aForm.isSigned()  << std::endl;
	os << "Grade required to sign: " << aForm.getGradeToSign() << std::endl;
	os << "Grade required to execute: " << aForm.getGradeToExecute() << std::endl;
	return os;
}