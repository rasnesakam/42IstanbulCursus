#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    RPN rpn;
    int result = rpn.calculate(argv[1]);

    if (result != -1)
        std::cout << result << std::endl;
    return 0;
}
