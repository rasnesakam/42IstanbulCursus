#include "Data.hpp"

Data::Data(){
	this->name = "";
	this->surname = "";
}
Data::Data(const std::string& name, const std::string&surname): name(name), surname(surname) {}
Data::~Data(){}
Data::Data(const Data& data){
	*this = data;
}
Data& Data::operator=(const Data& data){
	this->name = data.name;
	this->surname = data.surname;
	return *this;
}