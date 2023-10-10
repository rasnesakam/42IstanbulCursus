#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm: public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		void execute(const Bureaucrat& bureaucrat) const;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
		const std::string getTarget() const;
};
#endif