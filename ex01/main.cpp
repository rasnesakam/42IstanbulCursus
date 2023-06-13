#include "ClapTrap.hpp"

int main(void){
	ClapTrap ct_1("ct_1");
	ClapTrap ct_2("ct_2");
	ClapTrap ct_3("ct_3");
	
	for (int i = 0; i < 11; i++){
		ct_1.attack("ct_2");
		ct_2.takeDamage(0);
	}
	for (int i = 0; i < 11; i++){
		ct_3.takeDamage(1);
	}
	ct_3.attack("ct_1");
	ct_3.beRepaired(1);
	ct_3.attack("ct_1");

}