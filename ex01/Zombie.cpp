#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
    this->name = "unknown";
}

Zombie::Zombie(std::string name){
    this->name = name;
}

void Zombie::setName(std::string name){
    this->name = name;
}

void Zombie::anounce(void){
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " has died :(" << std::endl;
}