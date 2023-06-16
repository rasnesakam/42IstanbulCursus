#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name){
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;

}

FragTrap::FragTrap(FragTrap &fragTrap): ClapTrap(fragTrap){
	*this = fragTrap;
}

FragTrap& FragTrap::operator==(FragTrap &fragTrap){
	this->attackDamage = fragTrap.attackDamage;
	this->energyPoint = fragTrap.attackDamage;
	this->hitPoint = fragTrap.hitPoint;
	return *this;
}
