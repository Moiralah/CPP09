/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:26:40 by huidris           #+#    #+#             */
/*   Updated: 2026/03/24 13:26:41 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
