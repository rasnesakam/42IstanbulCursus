#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b = Bureaucrat("Raif Efendi", 1);
		Form my_form("Münazara Formu",1,2);
        std::cout << b << std::endl;
		std::cout << my_form << std::endl;
		b.signForm(my_form);
		return 0;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
