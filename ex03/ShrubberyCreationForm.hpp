#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm: public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
		ShrubberyCreationForm(const std::string& target);
		void execute(const Bureaucrat& bureaucrat) const;
		const std::string getTarget() const;
};
#endif