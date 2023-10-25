#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM
#include "AForm.hpp"
class RobotomyRequestForm: public AForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& form);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
		RobotomyRequestForm(const std::string& target);
		void execute(const Bureaucrat& bureaucrat) const;
		const std::string getTarget() const;
};

#endif