#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>


class PmergeMe
{
    private:
		double _elapsed_vector;
		double _elapsed_list;
        std::vector<int> _vector;
		std::list<int> _list;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe &operator = (const PmergeMe&);
        ~PmergeMe();
    	void sort_list(int argc, char *argv[]);
		void sort_vector(int argc, char *argv[]);

        double getElapsedVector();
		double getElapsedList();

        const std::vector<int> getVector() const;
        const std::list<int> getList() const;
		class ApplicationException : public std::exception{
			private:
				std::string message;
			public:
				ApplicationException(const std::string &message);
                ~ApplicationException() throw();
				const char* what() const throw();
		};
};



std::ostream& operator<<(std::ostream& os, const PmergeMe& mergeMe);

#endif
