#ifndef  ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include "Brain.hpp"

class Animal{
	protected:
		std::string type;
		Brain *brain;
	public:
		Animal();
		Animal(const std::string &type);
		~Animal();
		Animal(const Animal &animal);
		Animal& operator=(const Animal &animal);
		const std::string& getType() const;
		virtual void makeSound() const;
};

#endif