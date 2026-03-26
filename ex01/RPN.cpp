/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:26:33 by huidris           #+#    #+#             */
/*   Updated: 2026/03/26 15:27:29 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

int RPN::operation(std::string av)
{
	std::stringstream ss(av);
	std::string token;

	while (ss >> token)
	{
		if (token.size() > 1)
		{
			if ((token[0] == '-' || token[0] == '+' ) && isdigit(token[1]))
				throw std::runtime_error("Error: Only unsigned number allowed.");
			else if (isdigit(token[0]) && isdigit(token[1]))
				throw std::runtime_error("Error: Only single digit number allowed.");
			else
				throw std::runtime_error("Error: Invalid argument: " + token);
		}

		if (isdigit(token[0]))
		{
			_val.push(atoi(token.c_str()));
			continue;
		}

		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_val.size() < 2)
				throw std::runtime_error("Error: Invalid number of argument: " + token);

			int b = _val.top();
			_val.pop();
			int a = _val.top();
			_val.pop();

			if (token == "+")
				_val.push(a + b);
			if (token == "-")
				_val.push(a - b);
			if (token == "*")
				_val.push(a * b);
			if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error: Undefined number, infinity created.");
				_val.push(a / b);
			}
		}
		else
			throw std::runtime_error("Error: Invalid argument: " + token);
	}

	if (_val.size() != 1)
		throw std::runtime_error("Error: Invalid count of operation.");

	return _val.top();
}
