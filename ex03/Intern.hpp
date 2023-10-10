#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"
class Intern {
	public:
		Intern();
		~Intern();
		Intern(Intern &other);
		Intern& operator=(Intern &oth);
		AForm *makeForm(std::string name, std::string target);
		class InvalidFormException : public std::exception
		{
			public:
			const char *what();
		};
};

#endif