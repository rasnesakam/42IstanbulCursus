#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class ScavTrap: virtual public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		~ScavTrap();
		ScavTrap(ScavTrap &scavTrap);
		ScavTrap& operator=(ScavTrap &scavTrap);
		void guardGate();
};

#endif