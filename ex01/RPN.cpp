#include "RPN.cpp"

RPN::RPN(){}
RPN::~RPN(){}

int RPN::operation(std::string av)
{
    std::stringstream ss(av);
    std::string token;

    while(ss >> token)
    {
        if (isdigit(token))
            _val.push(atoi(token))
        else if(token =- "+" || token == "-" || token == "*" || token == "/")
        {
            if(_val.size() < 2)
                throw std::runtime_error("Error: Invalid number of argument.");

            int b = _val.top(); _val.pop();
            int a = _val.top(); _val.pop();

            if (token == "+")
                _val.push(a + b);
            if (token == "-")
                _val.push(a - b);
            if (token == "*")
                _val.push(a * b);
            if (token == "/")
                _val.push(a / b);
        }
        else
            throw std::runtime_error("Error: Invalid argument.");
    }

    if(_val.size() != 1)
        throw std::runtime_error("Error: Invalid count of operation.");
    
    return _val.top();
}

