#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>

class Bureaucrat;

class AForm{
	private:
		std::string name;
		bool signedd;
		int gradeToSign;
		int gradeToExecute;

	public:
		AForm();
		AForm(const std::string& name, int requiredGradeToSign,int requiredGradeToExecute);
		AForm(const AForm& oth);
		virtual ~AForm();
		AForm& operator=(const AForm& oth);
		const std::string& getName() const;
		const bool isSigned() const;
		const int getGradeToSign() const;
		const int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception{
			private:
				const char* message;
			public:
				GradeTooHighException(const std::string &message);
				const char* what();
		};
		class GradeTooLowException : public std::exception{
			private:
				const char* message;
			public:
				GradeTooLowException(const std::string &message);
				const char* what();
		};
		class FormNotSignedException : public std::exception{
			private:
				const char* message;
			public:
				FormNotSignedException(const std::string &message);
				const char* what();
		};
};

std::ostream& operator<<(std::ostream &stream, const AForm &form);

#endif
