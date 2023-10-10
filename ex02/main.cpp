#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b = Bureaucrat("Raif Efendi", 1);
		ShrubberyCreationForm my_form = ShrubberyCreationForm("hedef");
        std::cout << b << std::endl;
		std::cout << my_form << std::endl;
		b.signForm(my_form);
		b.executeForm(my_form);
		return 0;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
