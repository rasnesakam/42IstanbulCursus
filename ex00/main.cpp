#include "Bureucrat.hpp"
#include <iostream>
int main() {
    try {
        Bureucrat b("Raif Efendi", 1);
        Bureucrat c(b);
        std::cout << b << std::endl << c << std::endl;
        Bureucrat nejat("Nejat", 180);
        std::cout << nejat;
		return 0;
    }
    catch (Bureucrat::GradeTooHighException &tooHigh) {
        std::cerr << "GradeTooHighException: " << tooHigh.what() << std::endl;
    }
    catch (Bureucrat::GradeTooLowException &tooLow) {
        std::cerr << "GradeTooLowException: " << tooLow.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
