#include <cstdlib>
#include <ctime>
#include <iostream>	
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
		std::cerr << "Exception cached" << std::endl;
        std::cerr << e.what() << '\n';
    }
	std::cout << "Trying another test" << std::endl;
    try
    {
		std::cerr << "Exception cached" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    Array<int> ints = Array<int>(5);
    for (int i = 0; i < 5; i++){
        ints[i] = i;
    }
    std::cout << "integer array [0,1,2,3,4]" << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << ints[i] << std::endl;
    }
    delete [] mirror;
    return 0;

}
