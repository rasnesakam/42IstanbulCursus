#include "Cure.hpp"
#include <iostream>
Cure::Cure():AMateria("cure"){}

Cure::Cure(const Cure &cure){
    *this = cure;
}

Cure& Cure::operator=(const Cure &cure){
    if (this != &cure)
        AMateria::operator=(cure);
    return *this;
}

Cure::~Cure(){}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.getName() << "'s wounds";
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}