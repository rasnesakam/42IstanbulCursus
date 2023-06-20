#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap(){
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Creating empty FragTrap" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name){
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap creating with name: " << name << std::endl;
}

FragTrap::FragTrap(FragTrap &fragTrap): ClapTrap(fragTrap){
	*this = fragTrap;
	std::cout << "FragTrap cloning from name: " << name << std::endl;
}

FragTrap& FragTrap::operator==(FragTrap &fragTrap){
	this->attackDamage = fragTrap.attackDamage;
	this->energyPoints = fragTrap.attackDamage;
	this->hitPoints = fragTrap.hitPoints;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap with name " << this->name << " is destroying" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "Gimme the highest five ever!" << std::endl;
}

void FragTrap::attack(const std::string &name){
	if (this->energyPoints <= 0)
		std::cout << "Not enough energy points for FragTrap " << this->name << std::endl;
	if (this->hitPoints <= 0)
		std::cout << "Not enough hitPoints for FragTrap " << this->name << std::endl;
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "FragTrap " << this->name <<" attacks " << name <<", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}