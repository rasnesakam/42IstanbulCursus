#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& oth){
	*this = oth;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& oth){
	this->_list = oth._list;
	this->_vector = oth._vector;
	return *this;
}

PmergeMe::PmergeMe(int ac, char *argv[]){

	for (int i = 1; i < ac; i++){
		try{
			this->_list.push_back(std::stoi(std::string(argv[i])));
		}
		catch(std::invalid_argument& ex){
			throw InstantiationException();
		}
	}
}


PmergeMe::InstantiationException(std::string &message): message(message){}

const char* what() const throw(){
	return this->message.c_str();
}