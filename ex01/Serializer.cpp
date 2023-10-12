#include "Serializer.hpp"

std::uintptr_t Serializer::serialize(Data *data){
	return reinterpret_cast<uintptr_t>(data);
}

Data* Serializer::deserialize(uintptr_t ptr){
	return reinterpret_cast<Data *>(ptr);
}