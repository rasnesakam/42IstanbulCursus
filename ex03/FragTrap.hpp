#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{

	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(FragTrap &fragTrap);
		FragTrap& operator==(FragTrap &fragTrap);
		~FragTrap();
		void highFivesGuys(void);
};

#endif