#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &oth) { *this = oth; }
PmergeMe &PmergeMe::operator=(const PmergeMe &oth) {
  this->_list = oth._list;
  this->_vector = oth._vector;
  return *this;
}


PmergeMe::ApplicationException::ApplicationException(
    const std::string &message)
    : message(message) {}

const char *PmergeMe::ApplicationException::what() const throw() {
    return this->message.c_str();
}
PmergeMe::ApplicationException::~ApplicationException() throw(){}

std::list<int> start_sort_list(const std::list<int>::iterator &begin, const std::list<int>::iterator &last){
    if (std::distance(begin,last) > 2){
        std::list<int>::iterator mid = begin;
        std::advance(mid, std::distance(begin,last) / 2);
        std::list<int> l1 = start_sort_list(begin, mid);
        std::list<int> l2 = start_sort_list(mid, last);
        std::list<int> return_vec(l1.size() + l2.size());
        std::merge(l1.begin(),l1.end(),l2.begin(), l2.end(), std::back_inserter(return_vec));
        return return_vec;
    }
    try{
        std::list<int>::iterator next = begin;
        std::advance(next,1);
        std::list<int> return_list;
        if (next == last){
            return_list.push_back(*begin);
            return return_list;
        }
        if (*begin > *next)
        {
            int temp = *begin;
            *begin = *next;
            *next = temp;
        }
        return_list.push_back(*begin);
        return_list.push_back(*next);
        return return_list;
    }
    catch(std::exception& e){
        throw PmergeMe::ApplicationException("Unexpected Error.");
    }
}


std::vector<int> start_sort_vector(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &last){
    if (std::distance(begin,last) > 2){
        std::vector<int>::iterator mid = begin;
        std::advance(mid, 2);
        std::vector<int> l1 = start_sort_vector(begin, mid);
        std::vector<int> l2 = start_sort_vector(mid, last);
        std::vector<int> return_vec;
        return_vec.reserve(l1.size() + l2.size());
        std::merge(l1.begin(),l1.end(),l2.begin(), l2.end(), std::back_inserter(return_vec));
        return return_vec;
    }
    try{
        std::vector<int>::iterator next = begin + 1;
        std::vector<int> return_vec;
        if (next == last){
            return_vec.reserve(1);
            return_vec.push_back(*begin);
            return return_vec;
        }
        return_vec.reserve(2);
        if (*begin > *next)
        {
            int temp = *begin;
            *begin = *next;
            *next = temp;
        }
        return_vec.push_back(*begin);
        return_vec.push_back(*next);
        return return_vec;
    }
    catch(std::exception& e){
        throw PmergeMe::ApplicationException("Unexpected Error.");
    }
}

void PmergeMe::sort_vector(int argc, char* argv[]) {
    // Fill the array
    // TODO: start the counter
    clock_t start, end;
    for (int i = 1; i < argc; i++) {
        std::string value(argv[i]);
        int valueInt;
        if (!(std::stringstream(value) >> valueInt))
            throw ApplicationException(value + " is not convertible to integer");
        if (valueInt < 0)
            throw ApplicationException("Numbers must be positive");
        this->_vector.push_back(valueInt);
        
    }
    start = clock();
    this->_vector = start_sort_vector(this->_vector.begin(), this->_vector.end());
    end = clock();
    this->_elapsed_vector = (double)(end - start)/((double)CLOCKS_PER_SEC / 1000);
}

void PmergeMe::sort_list(int argc, char *argv[]) {
    // Fill the array
    // TODO: start the counter
    clock_t start, end;
    for (int i = 1; i < argc; i++) {
        std::string value(argv[i]);
        int valueInt;
        if (!(std::stringstream(value) >> valueInt))
            throw ApplicationException(value + " is not convertible to integer");
        if (valueInt < 0)
            throw ApplicationException("Numbers must be positive");
        this->_list.push_back(valueInt);
    }
    start = clock();
    this->_list = start_sort_list(this->_list.begin(), this->_list.end());
    end = clock();
    this->_elapsed_list = (double)(end - start)/((double)CLOCKS_PER_SEC / 1000);
}

double PmergeMe::getElapsedList() { return this->_elapsed_list; }
double PmergeMe::getElapsedVector() {
    return this->_elapsed_vector;
}

const std::list<int> PmergeMe::getList() const {
    return this->_list;
}
const std::vector<int> PmergeMe::getVector() const {
    return this->_vector;
}

std::ostream& operator<<(std::ostream& os, const PmergeMe& obj){
    for (std::vector<int>::size_type i = 0; i < obj.getVector().size(); i++){
        os << obj.getVector()[i] << " ";
    }
    return os;
}


