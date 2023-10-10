#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern someRandomIntern;
	Bureaucrat someRandomBureaucrat("Ali Nazik",1);
    AForm *rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
	someRandomBureaucrat.signForm(*rrf);
	someRandomBureaucrat.executeForm(*rrf);
	AForm *unknownForm;
	try {
		unknownForm = someRandomIntern.makeForm("unknown form", "Target");
		someRandomBureaucrat.signForm(*unknownForm);
		someRandomBureaucrat.executeForm(*unknownForm);
    	delete unknownForm;
	}catch(Intern::InvalidFormException& exception){
		std::cerr << exception.what() << std::endl;
	}
    delete rrf;

    return 0;
}
