#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN&)
{

}

RPN &RPN::operator = (const RPN&)
{
    return *this;
}

RPN::~RPN()
{
    
}

int RPN::calculate(const std::string &argv)
{
    std::stack<int> operands;
    
    int op1;
    int op2;
    bool hasOperator = false;
    
    size_t argvLen = argv.length();
    for (size_t i = 0; i < argvLen; i++)
    {
        char ch = argv[i];
    
        if (ch == ' ')
            continue;
        else if (isdigit(ch))
            operands.push(ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (operands.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return -1;
            }

            hasOperator = true;

            op2 = operands.top();
            operands.pop();
            op1 = operands.top();
            operands.pop();

            double result = -1;
            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    operands.push(result);
                    break;
                case '-':
                    result = op1 - op2;
                    operands.push(result);
                    break;
                case '*':
                    result = op1 * op2;
                    operands.push(result);
                    break;
                case '/':
                    if (op2 == 0)
                    {
                        std::cout << "Error" << std::endl;
                        return -1;
                    }
                    result = op1 / op2;
                    operands.push(result);
                    break;
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            return -1;
        }
    }

    if (!hasOperator && operands.size() == 1)
        return operands.top();

    if (operands.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return -1;
    }

    return operands.top();
}
