#ifndef PMERGEME_CPP
#define PMERGEME_CPP

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{

}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe&)
{

}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe&)
{
    return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{

}

template <typename Container>
void PmergeMe<Container>::insertion_sort(iterator left, iterator right)
{
    for (typename Container::iterator i = left; i != right; i++)
    {
        typename Container::value_type temp = *i;
        typename Container::iterator j = i;
        while (j != left && *(utils::prev(j)) > temp)
        {
            *j = *(utils::prev(j));
            j--;
        }
        *j = temp;
    }
}

template <typename Container>
void PmergeMe<Container>::merge_sort(Container &container, iterator left, iterator right)
{
    if (std::distance(left, right) <= 1)
        return;
    
    if (std::distance(left, right) < 10)
    {
        insertion_sort(left, right);
        return;
    }
    
    iterator middle = utils::next(left, std::distance(left, right) / 2);
    merge_sort(container, left, middle);
    merge_sort(container, middle, right);
    
    Container temp(std::distance(left, right));
    iterator i = left;
    iterator j = middle;
    iterator k = temp.begin();
    
    while (i != middle && j != right)
    {
        if (*i < *j)
        {
            *k = *i;
            i++;
        }
        else
        {
            *k = *j;
            j++;
        }
        k++;
    }
    
    while (i != middle)
    {
        *k = *i;
        i++;
        k++;
    }
    
    while (j != right)
    {
        *k = *j;
        j++;
        k++;
    }
    
    std::copy(temp.begin(), temp.end(), left);
}

template <typename Container>
void PmergeMe<Container>::merge_insertion_sort(Container &container)
{
    merge_sort(container, container.begin(), container.end());
}

template <typename Container>
Container PmergeMe<Container>::getInput(int argc, char *argv[])
{
    Container input;
    
    for (int i = 1; i < argc; i++)
    {
        char* token = strtok(argv[i], " ");

        while (token != NULL)
        {
            int num;
            bool valid = true;
            for (int i = 0; i < (int)strlen(token); i++)
            {
                if (!isdigit(token[i]))
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                num = atoi(token);
                if (num < 0)
                {
                    std::cout << "Error" << std::endl;
                    exit(1);
                }
                input.push_back(num);
            }
            else
            {
                std::cout << "Error" << std::endl;
                exit(1);
            }
            token = strtok(NULL, " ");
        }
    }

    return input;
}

template <typename Container>
void PmergeMe<Container>::display(Container& container)
{
    typedef typename Container::value_type value_type;

    std::string type;

    if (typeid(container).name() == typeid(std::list<value_type>).name())
        type = "std::list";
    else if (typeid(container).name() == typeid(std::vector<value_type>).name())
        type = "std::vector";
    else
        type = "unknown";

    std::cout << "Time to process a range of ";
    std::cout << container.size();
    std::cout << " elements with ";
    std::cout << type;
    std::cout << " : ";

    std::cout << std::fixed << std::setprecision(5) << _elapsedTime;
    std::cout << " us" << std::endl;
}

template <typename Container>
void PmergeMe<Container>::displaySorted()
{
    std::cout << "After: ";
    iterator it = _sorted.begin();
    while (it != _sorted.end())
    {
        std::cout << *it;
        std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe<Container>::displayUnsorted()
{
    std::cout << "Before: ";
    iterator it = _unsorted.begin();
    while (it != _unsorted.end())
    {
        std::cout << *it;
        std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe<Container>::setElapsedTime(clock_t start, clock_t end)
{
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    _elapsedTime = elapsedTime;
}

template <typename Container>
double PmergeMe<Container>::getElapsedTime() const
{
    return this->elapsedTime;
}

template <typename Container>
void PmergeMe<Container>::setSortedContainer(Container& container)
{
    iterator it = container.begin();
    iterator ite = container.end();
    
    _sorted.assign(it, ite);
}

template <typename Container>
void PmergeMe<Container>::setUnsortedContainer(Container& container)
{
    iterator it = container.begin();
    iterator ite = container.end();
    
    _unsorted.assign(it, ite);
}

#endif
