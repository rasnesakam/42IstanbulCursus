#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap {

	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap &diamondTrap);
		void whoAmI();
		void attack(const std::string &name);
};

#endif