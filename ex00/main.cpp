#include "Bureucrat.hpp"
#include <iostream>
int main(){
	try {
		Bureucrat b("Raif Efendi",1);
		Bureucrat c(b);
		std::cout << b << std::endl << c << std::endl;
		Bureucrat nejat("Nejat",180);
		std::cout << nejat;
	}
	catch (Bureucrat::GradeTooHighException tooHigh){
		std::cerr << tooHigh.what();
	}
	catch (Bureucrat::GradeTooLowException tooLow){
		std::cerr << tooLow.what();
	}
}