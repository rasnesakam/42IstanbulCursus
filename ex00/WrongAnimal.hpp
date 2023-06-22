#ifndef  WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include <string>

class WrongAnimal{
	protected:
		std::string type;
	
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &wrongAnimal);
		WrongAnimal& operator=(const WrongAnimal &wrongAnimal);
		const std::string& getType() const;
		void makeSound() const;
};

#endif