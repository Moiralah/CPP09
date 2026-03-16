#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stack>

class RPN
{
	private:
		std::stack<int> _val;
		RPN(RPN &);
		RPN &operator=(RPN &);

	public:
		RPN();
		~RPN();

		int operation(std::string);
};

#endif
