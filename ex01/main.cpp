#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    RPN rpn;
	try{
    	int result = rpn.calculate(argv[1]);
		std::cout << result << std::endl;
	}
	catch(std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
    return 0;
}
