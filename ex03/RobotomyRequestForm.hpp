#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM
#include "AForm.hpp"
class RobotomyRequestForm: public AForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& form);
		void execute(const Bureaucrat& bureaucrat) const;
		RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
		const std::string getTarget() const;
};

#endif