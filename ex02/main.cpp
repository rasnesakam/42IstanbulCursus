#include <iostream>	
#include "Array.hpp"

int main(void){

	    // Create an array of integers with 5 elements
    Array<int> intArray(5);

    // Access elements and set their values
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;
    intArray[3] = 40;
    intArray[4] = 50;

    // Copy the array
    Array<int> copiedArray = intArray;

    // Modify the original array
    intArray[2] = 35;

    // Display the elements in the copied array
    for (unsigned int i = 0; i < copiedArray.size(); i++) {
        std::cout << copiedArray[i] << " ";
    }

    return 0;
}