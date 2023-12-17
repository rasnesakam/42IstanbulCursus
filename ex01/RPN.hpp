#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <vector>

class RPN
{
    private:
        std::stack<int> operands;

    public:
        RPN();
        RPN(const RPN&);
        RPN &operator = (const RPN&);
        ~RPN();

        int calculate(const std::string &argv);
};

#endif