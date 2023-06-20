#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
int main(void){

	DiamondTrap dt("cafer");
	FragTrap ft("namık");
	ScavTrap st("borderlands");

	std::cout << std::endl;
	
	dt.attack("hüseyin");
	ft.attack("another one");

	std::cout << std::endl;
	dt.whoAmI();
	std::cout << std::endl;

	std::cout << std::endl;
}