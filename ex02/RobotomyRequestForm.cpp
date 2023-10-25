#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm(){
	this->target = "default";
}
RobotomyRequestForm::~RobotomyRequestForm(){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& oth){
	*this = oth;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& oth) {
	this->target = oth.target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm",25,5){
	this->target = target;
}

const std::string RobotomyRequestForm::getTarget() const {
	return target;
}


void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const{
	if (this->isSigned())
	{
		if (this->getGradeToExecute() >= bureaucrat.getGrade()){
			std::cout << "!!!!!!!!!!!!" << "SOME DRILLING NOISES" << "!!!!!!!!!!!! " << std::endl;
            srand(time(NULL));
            if(rand() % 2)
				std::cout << this->target << " has been robotomized successfully" << std::endl;
            else
                std::cout << "Faild to robotomize " << this->target  << std::endl;
		}
		else throw GradeTooHighException("the grade is too high");
	}
	else
		throw FormNotSignedException("Form Not Signed");
}