#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array{
	private:
		T *elements;
		unsigned int _size;
	public:
		Array(): elements(NULL), _size(0) {}
		Array(int len): _size(len) {
			this->elements = new T[len];
		}
		Array(const Array& oth){
			*this = oth;
		}
		Array& operator=(const Array& oth){
			this->_size = oth._size;
			if (this->elements != NULL)
				delete[] this->elements;
			this->elements = new T[oth._size];
			for (unsigned int i = 0; i < oth._size; i++){
				this->elements[i] = oth.elements[i];
			}
			return *this;
		}
		~Array(){
			delete[] this->elements;
		}
		T& operator[](unsigned int index){
			if (index < 0 || index > this->_size)
				throw std::out_of_range("Index out of bounds");
			return this->elements[index];
		}
		const unsigned int size() const{
			return this->_size;
		}
};

#endif