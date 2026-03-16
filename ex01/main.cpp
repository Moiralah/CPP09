#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid argument. ./RPN <string of calculation>" << std::endl;
		return 1;
	}

	try
	{
		RPN rpn;
		std::cout << rpn.operation(av[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
