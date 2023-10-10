#include "Intern.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{

}

Intern::~Intern(void)
{

}

Intern::Intern(Intern &other)
{
	
}

Intern& Intern::operator=(Intern &oth)
{
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form = NULL;
	std::string forms[] = {"Presidental Pardon", "Shrubbery Creation", "Robotomy Request"};
	int i = 0;
	while(i < 3 && forms[i] != name)
		i++;
	switch(i)
	{
		case(0):
			form = new PresidentialPardonForm(target);
			break;
		case(1):
			form = new ShrubberyCreationForm(target); 
			break;
		case(2):
			form = new RobotomyRequestForm(target);
			break;
		default:
			throw InvalidFormException();
	}
	std::cout << "Intern creates " << name << std::endl;
	return form;
}

const char *Intern::InvalidFormException::what(){
	return ("Form couldn't created");
}