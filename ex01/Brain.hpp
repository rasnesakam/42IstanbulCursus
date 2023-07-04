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
		void setIdeas(const std::string &idea);
		const std::string& getIdeas(int index) const;
};

#endif