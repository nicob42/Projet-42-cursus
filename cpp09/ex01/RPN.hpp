#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
public:
    RPN(const std::string& input);
    int evaluate();

private:
    std::stack<int> operands_;
    std::string input_;
    bool isOperator(const char& c);
};

#endif
