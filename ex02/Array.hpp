#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array{
	private:
		T *elements;
		unsigned int _size;
	public:
		Array(): elements(NULL), _size(0){}
		Array(unsigned int len): _size(len) {
			this->elements = new T[len];
		}
		Array(const Array& oth): elements(NULL), _size(0)
		{
			*this = oth;
		}
		Array& operator=(const Array& oth){
			if (this->elements != NULL)
				delete[] elements;
			this->elements = new T[oth._size];
			for (unsigned int i = 0; i < oth.size(); i++){
				this->elements[i] = oth.elements[i];
			}
			this->_size = oth._size;
			return *this;
		}
		~Array(){
			if (this->elements != NULL)
				delete[] this->elements;
		}
		T& operator[](unsigned int index){
			if (index >= this->size())
				throw std::out_of_range("Index out of bounds");
			return this->elements[index];
		}
		unsigned int size() const{
			return this->_size;
		}
};

#endif
