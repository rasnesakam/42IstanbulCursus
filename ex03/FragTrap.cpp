#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap(){
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "Creating empty FragTrap" << std::endl;
	std::cout << "FragTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitpoint: " << this->hitPoint << std::endl <<
			"\tenergyPoint: " << this->energyPoint << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name){
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap creating with name: " << name << std::endl;
	std::cout << "FragTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitpoint: " << this->hitPoint << std::endl <<
			"\tenergyPoint: " << this->energyPoint << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

FragTrap::FragTrap(FragTrap &fragTrap): ClapTrap(fragTrap){
	*this = fragTrap;
	std::cout << "FragTrap cloning from name: " << name << std::endl;
}

FragTrap& FragTrap::operator==(FragTrap &fragTrap){
	this->attackDamage = fragTrap.attackDamage;
	this->energyPoint = fragTrap.attackDamage;
	this->hitPoint = fragTrap.hitPoint;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap with name " << this->name << " is destroying" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "Gimme the highest five ever!" << std::endl;
}

void FragTrap::attack(const std::string &name){
	if (this->energyPoint <= 0)
		std::cout << "Not enough energy points for FragTrap " << this->name << std::endl;
	if (this->hitPoint <= 0)
		std::cout << "Not enough hitpoints for FragTrap " << this->name << std::endl;
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		this->energyPoint -= 1;
		std::cout << "FragTrap " << this->name <<" attacks " << name <<", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}