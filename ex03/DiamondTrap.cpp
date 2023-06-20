#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name("default")
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name){
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitPoints: " << this->hitPoints << std::endl <<
			"\tenergyPoints: " << this->energyPoints << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap){
	this->attackDamage = diamondTrap.attackDamage;
	this->hitPoints = diamondTrap.hitPoints;
	this->energyPoints = diamondTrap.energyPoints;
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