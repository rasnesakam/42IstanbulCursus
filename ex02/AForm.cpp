#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


AForm::AForm(){
	this->name = "";
	this->signedd = false;
	this->gradeToExecute = 150;
	this->gradeToSign = 150;
}
AForm::AForm(const AForm& oth){
	*this = oth;
}
AForm::~AForm(){}
AForm& AForm::operator=(const AForm& oth){
	this->name = oth.name;
	this->signedd = oth.signedd;
	this->gradeToSign = oth.gradeToSign;
	this->gradeToExecute = oth.gradeToExecute;
	return *this;
}

AForm::AForm(const std::string& name, int requiredGradeToSign, int requiredGradeToExecute){
	this->name = name;
	this->gradeToSign = requiredGradeToSign;
	this->gradeToExecute = requiredGradeToExecute;
	this->signedd = false;
}

const std::string& AForm::getName() const {
	return this->name;
}

bool AForm::isSigned() const{
	return this->signedd;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &message): message(message.c_str()) {}
const char* AForm::GradeTooHighException::what() const throw() {
    return message;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &message): message(message.c_str()){}

const char* AForm::GradeTooLowException::what() const throw() {
    return message;
}

AForm::FormNotSignedException::FormNotSignedException(const std::string &message): message(message.c_str()){}

const char* AForm::FormNotSignedException::what() const throw() {
    return message;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->signedd = true;
	else
		throw GradeTooLowException("Bureaucrat has too low grade to sign it");
}

std::ostream& operator<<(std::ostream &os, const AForm& aForm){
	os << "Name: " << aForm.getName() << std::endl;
	os << "Signed: " << aForm.isSigned()  << std::endl;
	os << "Grade required to sign: " << aForm.getGradeToSign() << std::endl;
	os << "Grade required to execute: " << aForm.getGradeToExecute() << std::endl;
	return os;
}