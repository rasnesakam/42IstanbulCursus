#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cstdio>
#include <typeinfo>
#include <cstring>
#include <string>


class PmergeMe
{
    private:
		double elapsed_vector;
		double elapsed_list;
        std::vector<int> _vector;
		std::list<int> _list;

    public:
        PmergeMe();
        PmergeMe(int len, char *numbers[]);
        PmergeMe(const PmergeMe&);
        PmergeMe &operator = (const PmergeMe&);
        ~PmergeMe();
        
        void display_list();
        void display_vector();

		void sort_list();
		void sort_vector();

        double getElapsedVector();
		double getElapsedList();
        void displaySorted();
        void displayUnsorted();
		class InstantiationException : public std::exception{
			private:
				std::string message;
			public:
				InstantiationException(std::string &message);
				const char* what() const throw();
		};
};

#include "PmergeMe.cpp"

#endif