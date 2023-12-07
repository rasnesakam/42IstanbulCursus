#include "iter.hpp"
#include <iostream>

void printChar(const char c)
{
	std::cout << c << " , ";
}

void printint(int a)
{
	std::cout << a << ",";
}

int main(void)
{
	char name[7] = "feriha";
	iter(name, 7, printChar);
	std::cout << std::endl;
	int arr[5] = {5, 1, 4, 8, 10};
	iter(arr, 5, printint);
	std::cout << std::endl;
}