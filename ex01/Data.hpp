#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data{
	public:
		std::string name;
		std::string surname;
		Data();
		Data(const std::string& name, const std::string&surname);
		~Data();
		Data(const Data& data);
		Data& operator=(const Data& data);
};

#endif