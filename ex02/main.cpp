#include "Base.hpp"
#include <iostream>

#include "functions.hpp"

int main(void)
{
	Base *a = generate();
	Base *b = generate();

	identify(a);
	identify(*b);
	
	delete a;
	delete b;
}