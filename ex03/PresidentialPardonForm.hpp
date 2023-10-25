#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM
#include "AForm.hpp"
class PresidentialPardonForm: public AForm {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		PresidentialPardonForm(const PresidentialPardonForm& form);
		PresidentialPardonForm(const std::string& target);
		void execute(const Bureaucrat& bureaucrat) const;
		const std::string getTarget() const;
};

#endif