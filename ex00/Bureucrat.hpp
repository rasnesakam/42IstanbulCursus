#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP
#include <string>

class Bureucrat {
	private:
		std::string name;
		unsigned char grade;
	public:
		class GradeTooHighException : public std::exception{
			private:
				const std::string &message;
			public:
				GradeTooHighException(const std::string &message);
				const char* what();
		};
		class GradeTooLowException : public std::exception{
			private:
				const std::string &message;
			public:
				GradeTooLowException(const std::string &message);
				const char* what();
		};
		Bureucrat();
		Bureucrat(const std::string &name, int grade);
		~Bureucrat();
		Bureucrat(const Bureucrat &bureucrat);
		Bureucrat& operator=(const Bureucrat &bureucrat);
		const std::string& getName() const;
		const int getGrade() const;
		void setGrade(int grade);
};

std::ostream& operator<<(std::ostream &stream, const Bureucrat &bureucrat);

#endif