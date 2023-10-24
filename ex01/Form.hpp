#ifndef FORM_HPP
#define FORM_HPP
#include <string>

class Bureaucrat;

class Form{
	private:
		std::string name;
		bool signedd;
		int gradeToSign;
		int gradeToExecute;

	public:
		Form();
		Form(const std::string& name, int requiredGradeToSign,int requiredGradeToExecute);
		Form(const Form& oth);
		~Form();
		Form& operator=(const Form& oth);
		const std::string& getName() const;
		const bool isSigned() const;
		const int getGradeToSign() const;
		const int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
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
};

std::ostream& operator<<(std::ostream &stream, const Form &form);

#endif