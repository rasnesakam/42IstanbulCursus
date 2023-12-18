#include "PmergeMe.hpp"
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char *argv[])
{
    try{
        PmergeMe mergeMe;
        mergeMe.sort_list(argc,argv);
        mergeMe.sort_vector(argc,argv);
        std::cout << "Before:\t";
        for (int i = 1; i < argc; i++)
            std::cout << std::string(argv[i]) << " ";
        std::cout << std::endl;
        std::cout << "After:\t" << mergeMe << std::endl;
        std::cout << "Time to process\t" << argc - 1 << " elements with std::vector :\t" << mergeMe.getElapsedVector() << " ms" << std::endl;
        std::cout << "Time to process\t" << argc - 1 << " elements with std::list :\t" << mergeMe.getElapsedList() << " ms" << std::endl;
        return 0;
    }
    catch (PmergeMe::ApplicationException &ex){
        std::cerr << "Error" << ex.what() << std::endl;
        return 1;
    }
}
