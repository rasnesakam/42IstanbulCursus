#ifndef  ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include "Brain.hpp"

class Animal{
	protected:
		std::string type;
		Brain *brain;
		Animal(const Animal &animal);
		Animal();
		Animal(const std::string &type);
	public:
		~Animal();
		Animal& operator=(const Animal &animal);
		const std::string& getType() const;
		virtual void makeSound() const;
};

#endif