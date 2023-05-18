#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){
    this->name = "unknown";
}

Zombie::Zombie(std::string name){
    this->name = name;
}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->name << " has died :(" << std::endl;
}

void Zombie::anounce(void){
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
