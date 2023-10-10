#include "Bureaucrat.hpp"
#include <iostream>
int main() {
    try {
        Bureaucrat b("Raif Efendi", 1);
        Bureaucrat c(b);
        std::cout << b << std::endl << c << std::endl;
        Bureaucrat nejat("Nejat", 180);
        std::cout << nejat;
		return 0;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
