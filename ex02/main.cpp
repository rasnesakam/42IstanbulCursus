#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    clock_t start;
    clock_t end;

    {
        PmergeMe< std::vector<int> > _pmergeMe;
        std::vector<int> input = _pmergeMe.getInput(argc, argv);
        std::vector<int> holder(input.begin(), input.end());

        start = clock();
        _pmergeMe.merge_insertion_sort(holder);
        end = clock();

        _pmergeMe.setElapsedTime(start, end);
        _pmergeMe.setUnsortedContainer(input);
        _pmergeMe.setSortedContainer(holder);
        _pmergeMe.displayUnsorted();
        _pmergeMe.displaySorted();
        _pmergeMe.display(holder);
    }

    
    {
        PmergeMe< std::list<int> > _pmergeMe;
        std::list<int> input = _pmergeMe.getInput(argc, argv);
        std::list<int> holder(input.begin(), input.end());

        start = clock();
        _pmergeMe.merge_insertion_sort(holder);
        end = clock();

        _pmergeMe.setElapsedTime(start, end);
        _pmergeMe.setUnsortedContainer(input);
        _pmergeMe.setSortedContainer(holder);

        _pmergeMe.display(holder);
    }
    // system("leaks PmergeMe");
    return 0;
}