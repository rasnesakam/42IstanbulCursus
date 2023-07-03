#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(){
    this->type = "undefined";
}

AMateria::AMateria(const std::string &type){
    this->type = type;
}

AMateria::AMateria(const AMateria &materia){
    *this = materia;
}

AMateria& AMateria::operator=(const AMateria &materia){
    this->type = materia.getType();
    return *this;
}

AMateria::~AMateria(){}

const std::string& AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter &target){
    std::cout << target.getName() << " used undefined materia" << std::endl;
}