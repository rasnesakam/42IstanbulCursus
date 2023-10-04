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
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
