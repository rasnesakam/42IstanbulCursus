#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();
		Brain& operator=(const Brain &brain);
};

#endif