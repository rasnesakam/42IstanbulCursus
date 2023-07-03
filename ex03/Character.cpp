#include "Character.hpp"

Character::Character(){
    this->name = "undefined";
    for (int i = 0; i < 4; i++){
        this->materia[i] = NULL;
    }
}

Character::Character(const std::string &name){
    this->name = name;
    for (int i = 0; i < 4; i++){
        this->materia[i] = NULL;
    }
}

Character::Character(const Character &character): name(character.name){
    for (int i = 0; i < 4; i++){
        this->materia[i] = character.materia[i] ? character.materia[i]->clone() : NULL;
    }
}

Character& Character::operator=(const Character &character){
    if (&character != this){
        this->~Character();
        this->name = character.getName();
        for (int i = 0; i < 4; i++){
            this->materia[i] = character.materia[i] ? character.materia[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character(){
    for (int i = 0; i < 4; i++)
        if (this->materia[i] != NULL)
            delete this->materia[i];
}

const std::string& Character::getName() const {
    return this->name;
}

void Character::equip(AMateria *m){
    int index = 0;
    while (this->materia[index] != NULL)
        index++;
    if (index < 4)
        materia[index] = m;
}

void Character::unequip(int idx){
    if (idx < 4 && idx >= 0){
        this->materia[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target){
    if (idx < 4 && idx >= 0 && this->materia[idx] != NULL)
        this->materia[idx]->use(target);
}