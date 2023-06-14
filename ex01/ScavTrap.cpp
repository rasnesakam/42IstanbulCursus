#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	this->attackDamage = 20;
	this->hitPoint = 100;
	this->energyPoint = 50;
}

ScavTrap::~ScavTrap(){

}

ScavTrap::ScavTrap(ScavTrap &scavTrap): ClapTrap(scavTrap){
	*this = scavTrap;
}

ScavTrap& ScavTrap::operator=(ScavTrap &scavTrap){
	this->name = scavTrap.name;
	this->attackDamage = scavTrap.attackDamage;
	this->hitPoint = scavTrap.hitPoint;
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}