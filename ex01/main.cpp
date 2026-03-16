#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Invalid argument" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn;
        std::cout << rpn.operate(av[1]) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<< e.what();
    }

    return 0;
}