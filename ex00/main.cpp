#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int ac, char **av){

	if (ac == 2){
		std::string literal(av[1]);
		ScalarConverter::convert(literal);
		return 0;
	}
	else
		std::cerr << "You need to pass one literal" << std::endl;
	return 1;
}