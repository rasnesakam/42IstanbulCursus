#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default")
{
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name){
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitpoint: " << this->hitPoint << std::endl <<
			"\tenergyPoint: " << this->energyPoint << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap){
	this->attackDamage = diamondTrap.attackDamage;
	this->hitPoint = diamondTrap.hitPoint;
	this->energyPoint = diamondTrap.energyPoint;
	this->name = diamondTrap.name;
	this->ClapTrap::name = diamondTrap.ClapTrap::name;
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Destructor called for diamondTrap" << std::endl;
}

void DiamondTrap::attack(const std::string &name){
	ScavTrap::attack(name);
}

void DiamondTrap::whoAmI(){
	std::cout << "I am " << this->name << " A.K.A. " << ClapTrap::name << std::endl;
}