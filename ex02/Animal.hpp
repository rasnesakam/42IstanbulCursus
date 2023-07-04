#ifndef  ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include "Brain.hpp"

class Animal{
	protected:
		std::string type;
		Animal(const Animal &animal);
		Animal();
		Animal(const std::string &type);
	public:
		virtual ~Animal();
		Animal& operator=(const Animal &animal);
		const std::string& getType() const;
		virtual void makeSound() const;
};

#endif