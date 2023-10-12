#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include "Data.hpp"

class Serializer{
	public:
		static std::uintptr_t serialize(Data *data);
		static Data* deserialize(std::uintptr_t data);
};

#endif