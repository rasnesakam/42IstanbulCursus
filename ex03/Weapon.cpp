#include "Weapon.hpp"


Weapon::Weapon(void) {
    this->type = "bare hands";
}


Weapon::Weapon(std::string type) {
    this->type = type;
}

void Weapon::setType(std::string type){
    this->type = type;
}

std::string Weapon::getType(){
    return this->type;
}