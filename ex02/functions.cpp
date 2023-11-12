#include "functions.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Base * generate(void){
	srand(time(NULL));
	int random = rand();
	random = random % 3;
	Base *base; 
	switch(random){
		case(0):
			base = new A;
			break;
		case(1):
			base = new B;
			break;
		case(2):
			base = new C;
			break;
		default:
			base = new A;
			break;
	}
	return (base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p)  != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" <<std::endl;
}

void identify(Base& p)
{
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception &e) {}	
	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception &e) {}	
	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception &e) {}
}