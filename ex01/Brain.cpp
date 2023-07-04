#include "Brain.hpp"
#include <iostream>

Brain::Brain(){

	std::cout << "Brain created" <<  std::endl;
}

Brain::Brain(const Brain &brain){
	*this = brain;
	std::cout << "Brain Copied" <<  std::endl;
}

Brain& Brain::operator=(const Brain &brain){
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = brain.ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain deleted" <<  std::endl;
}

void Brain::setIdeas(const std::string &idea){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}

const std::string& Brain::getIdeas(int index) const{
	return this->ideas[index];
}