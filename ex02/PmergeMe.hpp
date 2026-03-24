/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:02:02 by huidris           #+#    #+#             */
/*   Updated: 2026/03/24 13:02:26 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <exception>

struct pair
{
	size_t small;
	size_t big;
};

class PmergeMe
{

	private:
		std::vector<size_t> _vec;
		std::deque<size_t> _deq;

		void fordJohnsonVector(std::vector<size_t> &arr);
		void fordJohnsonDeque(std::deque<size_t> &arr);

		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);

	public:
		PmergeMe(char **av);
		~PmergeMe();

		void process_input();
};

#endif
