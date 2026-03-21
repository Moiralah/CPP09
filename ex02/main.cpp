#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Wrong input" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe p(av);
        p.process_input();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}