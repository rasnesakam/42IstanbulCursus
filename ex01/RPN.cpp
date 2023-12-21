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

int sum(int a, int b){ return a + b;}
int substract(int a, int b){ return a - b;}
int multiply(int a, int b){ return a * b;}
int divide(int a, int b){ return a / b; }

void update_stack(std::stack<int>& stack_ref, int (*operation)(int,int)){
	int arg_2 = stack_ref.top();
	stack_ref.pop();
	int arg_1 = stack_ref.top();
	stack_ref.pop();
	stack_ref.push(operation(arg_1, arg_2));
}

int RPN::calculate(const std::string &expression)
{
    std::stack<int> buffer;
    size_t expressionLen = expression.length();
    for (size_t i = 0; i < expressionLen; i++)
    {
        char ch = expression[i];
		switch (ch){
			case ' ':
				break;
			case '+':
				update_stack(buffer, sum);
				break;
			case '-':
				update_stack(buffer, substract);
				break;
			case '*':
				update_stack(buffer, multiply);
				break;
			case '/':
				update_stack(buffer, divide);
				break;
			default:
				if (isdigit(ch)){
					if (i == expressionLen - 1 || isspace(expression[i + 1])){
						std::cout << "index: " << i << " token: >" << expression[i + 1] << "<" << std::endl;
						buffer.push(ch - '0');
					}
					else
						throw std::runtime_error("Unexpected token '" + std::string(1, ch) + "' at column: " + std::to_string(i));
				}
				else
					throw std::runtime_error("Invalid token: " + std::string(1, ch));
				break;
		}
        
    }

	if (buffer.size() > 1)
		throw std::runtime_error("Invalid expression.");
    return buffer.top();
}
