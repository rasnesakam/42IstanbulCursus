#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name){
	std::cout << "New " << name << " occured in environment" << std::endl;
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
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
}

ClapTrap::~ClapTrap(){}

void ClapTrap::attack(const std::string &target){
	std::cout << "ClapTrap " << this->name <<" attacks " << target <<", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){}

void ClapTrap::beRepaired(unsigned int amount){}