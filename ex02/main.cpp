#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
int main(void){

	ScavTrap st_1("st_1");
	ClapTrap ct_1("ct_1");
	FragTrap ft_1("ft_1");
	
	st_1.guardGate();
	ct_1.attack("st_1");
	st_1.takeDamage(1);
	ct_1.attack("st_1");
	st_1.attack("ct_1");
	ct_1.takeDamage(20);
	ct_1.attack("st_1");
	ft_1.attack("st_1");
	st_1.takeDamage(30);
	ft_1.attack("st_1");
	st_1.takeDamage(30);
	ft_1.highFivesGuys();
}