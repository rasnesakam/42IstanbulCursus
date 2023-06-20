#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): name("Default") , hitPoint(10), energyPoint(10), attackDamage(0){
	std::cout << "New ClapTrap occured in environment" << std::endl;
	std::cout << "ClapTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitpoint: " << this->hitPoint << std::endl <<
			"\tenergyPoint: " << this->energyPoint << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name){
	std::cout << "New " << name << " occured in environment" << std::endl;
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap created with values" << std::endl << 
		"{" << std::endl <<
			"\tname: " << this->name << std::endl <<
			"\thitpoint: " << this->hitPoint << std::endl <<
			"\tenergyPoint: " << this->energyPoint << std::endl <<
			"\tattackDamage: " << this->attackDamage << std::endl <<
		"}" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &target){
	std::cout << "New " << name << " cloned from another one." << std::endl;
	*(this) = target;
}

ClapTrap& ClapTrap::operator=(ClapTrap &target){
	this->name = target.name;
	this->hitPoint = target.hitPoint;
	this->energyPoint = target.energyPoint;
	this->attackDamage = target.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "A ClapTrap " << this->name << " vanished into the abyss of nothingness" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->energyPoint <= 0)
		std::cout << "Not enough energy points for ClapTrap " << this->name << std::endl;
	if (this->hitPoint <= 0)
		std::cout << "Not enough hitpoints for ClapTrap " << this->name << std::endl;
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		this->energyPoint -= 1;
		std::cout << "ClapTrap " << this->name <<" attacks " << target <<", causing " << this->attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	this->hitPoint -= amount;
	std::cout << "ClapTrap " << this->name <<" recieved " << amount <<" of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoint <= 0)
		std::cout << "Not enough energy points for ClapTrap " << this->name << std::endl;
	if (this->hitPoint <= 0)
		std::cout << "Not enough hitpoints for ClapTrap " << this->name << std::endl;
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		this->energyPoint -= 1;
		std::cout << "ClapTrap " << this->name <<" remains " << amount <<" of heal back" << std::endl;
	}
}