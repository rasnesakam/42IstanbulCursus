#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {

	Animal *animals[10];

	for (int i = 0; i < 10; i++){
		if (i < 5)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}

	for (int i = 0; i < 10; i++)
		delete animals[i];

	return 0; 
}