#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM
#include "AForm.hpp"
class PresidentialPardonForm: public AForm {
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		void execute(const Bureaucrat& bureaucrat) const;
		const std::string getTarget() const;
};

#endif