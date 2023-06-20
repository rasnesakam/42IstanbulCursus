#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string &name): ClapTrap(name){
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "Creating empty FragTrap" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name){
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap creating with name: " << name << std::endl;
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