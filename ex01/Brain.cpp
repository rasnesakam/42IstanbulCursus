#include "Brain.hpp"

Brain::Brain(){}

Brain::Brain(const Brain &brain){
	*this = brain;
}

Brain& Brain::operator=(const Brain &brain){
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	return *this;
}