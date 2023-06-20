#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(): ClapTrap(){
	
	std::cout << "Creating empty ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name){
	this->attackDamage = 20;
	this->hitPoints = 100;
	this->energyPoints = 50;
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
	this->hitPoints = scavTrap.hitPoints;
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &name){
	if (this->energyPoints <= 0)
		std::cout << "Not enough energy points for ScavTrap " << this->name << std::endl;
	if (this->hitPoints <= 0)
		std::cout << "Not enough hitPoints for ScavTrap " << this->name << std::endl;
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ScavTrap " << this->name <<" attacks " << name <<", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}