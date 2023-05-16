#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string label){
	int index = -1;
	const char *labels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fun[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
		if (std::strcmp(labels[i],label.c_str()) == 0)
			index = i;
	if (index == -1){
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	std::cout << "[ " << labels[index] << " ]" << std::endl;
	(this->*fun[index])();
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month" << std::endl;
}