#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap {

	public:
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap &scavTrap);
		ScavTrap& operator=(ScavTrap &scavTrap);
		void guardGate();
		void attack(const std::string &name);
};

#endif