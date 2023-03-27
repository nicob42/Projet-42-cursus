#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

RPN::RPN(const std::string& input) : input_(input) {}

int RPN::evaluate()
{
    for (size_t i = 0; i < input_.size(); ++i)
    {
        if (isdigit(input_[i]))
        {
            operands_.push(input_[i] - '0');
        }
        else if (isOperator(input_[i]))
        {
            if (operands_.size() < 2)
            {
                throw std::runtime_error( "Error: insufficient operands for operator.");
            }
            int operand2 = operands_.top();
            operands_.pop();
            int operand1 = operands_.top();
            operands_.pop();
            int result;
            switch (input_[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        throw std::runtime_error( "Error: can't divide by zero.");
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    throw std::runtime_error("Error: unknown operator.");
            }
            operands_.push(result);
        }
        else if (isspace(input_[i]))
        {
            continue;
        }
        else
        {
            throw std::runtime_error( "Error.");
        }
    }
    if (operands_.size() != 1)
    {
        throw std::runtime_error( "Error: Not enough argument.");
    }
    return operands_.top();
}

bool RPN::isOperator(const char& c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
