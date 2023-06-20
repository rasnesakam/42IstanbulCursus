#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): name("Default") , hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "New ClapTrap occured in environment" << std::endl;
	std::cout << "ClapTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitPoints: " << this->hitPoints << std::endl <<
			"\tenergyPoints: " << this->energyPoints << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name){
	std::cout << "New " << name << " occured in environment" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitPoints: " << this->hitPoints << std::endl <<
			"\tenergyPoints: " << this->energyPoints << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &target){
	std::cout << "New " << name << " cloned from another one." << std::endl;
	*(this) = target;
}

ClapTrap& ClapTrap::operator=(ClapTrap &target){
	this->name = target.name;
	this->hitPoints = target.hitPoints;
	this->energyPoints = target.energyPoints;
	this->attackDamage = target.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "A ClapTrap " << this->name << " vanished into the abyss of nothingness" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->energyPoints <= 0)
		std::cout << "Not enough energy points for ClapTrap " << this->name << std::endl;
	if (this->hitPoints <= 0)
		std::cout << "Not enough hitPoints for ClapTrap " << this->name << std::endl;
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << this->name <<" attacks " << target <<", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name <<" recieved " << amount <<" of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints <= 0)
		std::cout << "Not enough energy points for ClapTrap " << this->name << std::endl;
	if (this->hitPoints <= 0)
		std::cout << "Not enough hitPoints for ClapTrap " << this->name << std::endl;
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << this->name <<" remains " << amount <<" of heal back" << std::endl;
	}
}