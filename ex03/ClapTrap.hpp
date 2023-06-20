#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <string>

class ClapTrap{

	protected:
		std::string name;
		int hitPoint;
		int energyPoint;
		int attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(ClapTrap &clapTrap);
		ClapTrap& operator=(ClapTrap &clapTrap);
		~ClapTrap();

		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif