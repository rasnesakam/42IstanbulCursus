#ifndef HARL_HPP
#define HARL_HPP
#include <string>

class Harl {
	private:

	public:
		void error(void);
		void info(void);
		void debug(void);
		void warning(void);
		void complain(std::string label);
};

#endif