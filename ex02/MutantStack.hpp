#include <stack>
#include <vector>

template <typename Type>
class MutantStack: public std::stack<Type>{

	private:

	public:

		MutantStack(): std::stack<Type>(){}
        MutantStack(const MutantStack<Type>& oth): std::stack<Type>(oth) {}
        MutantStack<Type>& operator=(const MutantStack<Type>& oth) {
            this->c = oth.c;
            return *this;
        }
        virtual ~MutantStack(){}
        // iterator type definitions
        typedef typename std::stack<Type>::container_type::iterator iterator;
        typedef typename std::stack<Type>::container_type::const_iterator const_iterator;
        typedef typename std::stack<Type>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<Type>::container_type::const_reverse_iterator const_reverse_iterator;
		        
        iterator begin(){
            return this->c.begin();
        }
        const_iterator begin() const {
            return this->c.begin();
        }

        reverse_iterator rbegin() {
            return this->c.rbegin();
        }
        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }

        iterator end(){
            return this->c.end();
        }
};
