#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM
#include "AForm.hpp"
class PresidentialPardonForm: public AForm {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& form);
		void execute(const Bureaucrat& bureaucrat) const;
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		const std::string getTarget() const;
};

#endif