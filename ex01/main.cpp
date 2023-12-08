#include "iter.hpp"
#include <iostream>


int main(void)
{
	char name[7] = "feriha";
	iter(name, 7, print);
	std::cout << std::endl;
	int arr[5] = {5, 1, 4, 8, 10};
	iter(arr, 5, print);
	std::cout << std::endl;
}