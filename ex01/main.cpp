#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"
int main(){
	Data *data = new Data("Ensar", "Makas");
	uintptr_t ptr =  Serializer::serialize(data);
	std::cout << "Address: " << ptr << std::endl;
	Data *converted = Serializer::deserialize(ptr);
	std::cout << "Name: " << converted->name << std::endl << "Surname: " << converted->surname << std::endl;
	delete converted;
}