#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++){
		this->materia[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource){
	for (int i = 0; i < 4; i++){
		this->materia[i] = materiaSource.materia[i] ? materiaSource.materia[i]->clone() : NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materiaSource){
	if (&materiaSource != this){
		this->~MateriaSource();
		for (int i = 0; i < 4; i++)
			this->materia[i] = materiaSource.materia[i] ? materiaSource.materia[i]->clone() : NULL;
	} 
	return *this;
}

MateriaSource::~MateriaSource(){
	    for (int i = 0; i < 4; i++)
        if (this->materia[i])
            delete this->materia[i];

}

void MateriaSource::learnMateria(AMateria *materia){
	int index = 0;
	while (this->materia[index] != NULL)
		index++;
	if (index < 4)
		this->materia[index] = materia;
}

AMateria* MateriaSource::createMateria(const std::string &type){
	for (int i = 0; i < 4; i++){
		if (this->materia[i]->getType() == type)
			return this->materia[i]->clone();
	}
	return NULL;
}