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


namespace utils
{
    template<class T>
    T prev(T it, typename std::iterator_traits<T>::difference_type n = 1)
    {
        std::advance(it, -n);
        return it;
    }

    template<class T>
    T next(T it, typename std::iterator_traits<T>::difference_type n = 1)
    {
        std::advance(it, n);
        return it;
    }
}

template <typename Container>
class PmergeMe
{
    private:
        typedef typename Container::iterator iterator;

        void insertion_sort(iterator left, iterator right);
        void merge_sort(Container& container, iterator left, iterator right);

        double _elapsedTime;

        Container _sorted;
        Container _unsorted;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe&);
        PmergeMe &operator = (const PmergeMe&);
        ~PmergeMe();
        
        void merge_insertion_sort(Container& container);
        void display(Container& container);
        Container getInput(int argc, char *argv[]);

        void setElapsedTime(clock_t start, clock_t end);
        double getElapsedTime() const;

        void setSortedContainer(Container& container);
        void setUnsortedContainer(Container& container);

        void displaySorted();
        void displayUnsorted();
};

#include "PmergeMe.cpp"

#endif