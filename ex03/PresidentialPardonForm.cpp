#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm",25,5){
	this->target = target;
}

const std::string PresidentialPardonForm::getTarget() const {
	return target;
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const{
	if (this->isSigned())
    {
        if (bureaucrat.getGrade() <= this->getGradeToExecute())
            std::cout << " has been pardoned by Zaphod Beeblebrox. " << std::endl;
        else
            throw AForm::GradeTooLowException("");
    }
    else
        throw FormNotSignedException("Form not signed");
}