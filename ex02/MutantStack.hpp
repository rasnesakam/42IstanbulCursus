#include <stack>
#include <vector>

template <typename Type>
class MutantStack{

	private:
		unsigned int _index;
		unsigned int _size;
		std::vector<Type> _stack;

	public:

		MutantStack();
		bool empty();
		unsigned int size() const;
		Type top();
		void pop();
		void push(const Type& element);
		void emplace(Type element);

		class iterator {
			private:
				Type *current;
			
			public:
				iterator(Type *ptr):current(ptr);
				
				Type& operator*();
				
				// increments
				iterator& operator++();
				iterator operator++(int);

				// decrements
				iterator& operator--();
				iterator operator--(int);

				bool operator==(const iterator& oth);
				bool operator=!(const iterator& oth);
		}

};
