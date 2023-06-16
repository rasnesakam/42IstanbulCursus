#include "ScavTrap.hpp"
#include <iostream>
int main(void){

	ScavTrap st_1("st_1");
	ClapTrap ct_1("ct_1");
	
	st_1.guardGate();
	for (int i = 0; i < 10; i++){
		ct_1.attack("st_1");
		st_1.takeDamage(1);
	}
	ct_1.attack("st_1");
	st_1.attack("ct_1");
	ct_1.takeDamage(20);
	ct_1.attack("st_1");

}