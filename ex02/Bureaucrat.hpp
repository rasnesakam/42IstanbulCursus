#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>

class AForm;

class Bureaucrat {
	private:
		std::string name;
		unsigned char grade;
	public:
		class GradeTooHighException : public std::exception{
			private:
				const char* message;
			public:
				GradeTooHighException(const std::string &message);
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			private:
				const char* message;
			public:
				GradeTooLowException(const std::string &message);
				const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &Bureaucrat);
		Bureaucrat& operator=(const Bureaucrat &Bureaucrat);
		const std::string& getName() const;
		const int getGrade() const;
		void setGrade(int grade);
		void incGrade();
		void decGrade();
		void signForm(AForm& form);
		void executeForm(const AForm& form);
};

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat);

#endif