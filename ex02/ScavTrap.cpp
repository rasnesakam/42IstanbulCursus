#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name){
	this->attackDamage = 20;
	this->hitPoint = 100;
	this->energyPoint = 50;
	std::cout << "ScavTrap creating with name: " << name << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap with name " << this->name << " is destroying" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &scavTrap): ClapTrap(scavTrap){
	*this = scavTrap;
	std::cout << "ScavTrap cloning from name: " << this->name << std::endl;
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