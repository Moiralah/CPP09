/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:01:49 by huidris           #+#    #+#             */
/*   Updated: 2026/03/24 13:34:51 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ----- constructor & destructor -----//

PmergeMe::PmergeMe(char **av)
{
	for (size_t i = 1; av[i]; i++)
	{
		std::string val = av[i];
		if (val.size() > 1 && (val[0] == '-' || val[0] == '+') && isdigit(val[1]))
			throw std::runtime_error("Error: Only unsigned number allowed.");

		for (size_t j = 0; j < val.size(); j++)
			if (!isdigit(val[j]))
				throw std::runtime_error("Error: Only digit allowed");

		long n = atol(av[i]);
		if (n > 2147483647)
			throw std::runtime_error("Error: Number too large ");

		if (std::find(_vec.begin(), _vec.end(), n) != _vec.end())
			throw std::runtime_error("Error: Duplicate number not allowed ");
		_vec.push_back(n);
		_deq.push_back(n);
	}
}

PmergeMe::~PmergeMe() {}

// ----- ALL THE HELPER and THE GANG ----- //

template <typename T>
void printing(T &container)
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// ------- static jacobsthal generator -------//

template <typename Container>
Container jacobsthal(size_t n)
{
	Container seq;

	if (n == 0)
		return seq;

	size_t js0 = 1; // curb starting point at 1
	size_t js1 = 1;

	while (js1 < n)
	{
		seq.push_back(js1);
		size_t next = js1 + 2 * js0;
		js0 = js1;
		js1 = next;
	}
	return seq;
}

// ------ binary insertion template for both container -----//
template <typename T>
typename T::iterator binarySearchInsert(T &container, size_t value)
{
	return std::lower_bound(container.begin(), container.end(), value);
}

bool compareByBig(const pair &a, const pair &b)
{
	return a.big < b.big;
}

// ------ make pairs ------ //
template <typename Container, typename PairContainer>
void makePairs(Container &arr, PairContainer &pairs)
{
	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		pair p;
		size_t x = arr[i];
		size_t y = arr[i + 1];

		if (x < y)
		{
			p.small = x;
			p.big = y;
		}
		else
		{
			p.small = y;
			p.big = x;
		}
		pairs.push_back(p);
	}
}

// ------ fordJohnson algo for vec and deq ----- //
void PmergeMe::fordJohnsonVector(std::vector<size_t> &arr)
{
	if (arr.size() <= 1)
		return;

	// make pair
	std::vector<pair> pairs;
	makePairs(arr, pairs);
	std::sort(pairs.begin(), pairs.end(), compareByBig);

	// flag and store leftover
	int left = -1;
	if (arr.size() % 2)
		left = arr.back();

	// storing winner among the pair
	std::vector<size_t> winner;
	for (size_t i = 0; i < pairs.size(); i++)
		winner.push_back(pairs[i].big);

	// recursively find the ultimate winner
	fordJohnsonVector(winner);
	std::vector<size_t> result = winner;

	std::vector<size_t> loser;
	for (size_t i = 0; i < pairs.size(); i++)
		loser.push_back(pairs[i].small);

	std::vector<size_t> jsSeq = jacobsthal<std::vector<size_t> >(loser.size());
	for (size_t i = 0; i < jsSeq.size(); i++)
	{
		size_t idx = jsSeq[i] - 1;
		if (idx >= loser.size())
			continue;
		size_t value = loser[idx];
		std::vector<size_t>::iterator pos =
			binarySearchInsert(result, value);
		result.insert(pos, value);
	}

	for (size_t i = 0; i < loser.size(); i++)
	{
		size_t value = loser[i];
		if (std::find(result.begin(), result.end(), value) != result.end())
			continue;
		std::vector<size_t>::iterator pos =
			binarySearchInsert(result, value);
		result.insert(pos, value);
	}

	if (left != -1)
	{
		std::vector<size_t>::iterator pos =
			binarySearchInsert(result, left);
		result.insert(pos, left);
	}
	arr = result;
}

void PmergeMe::fordJohnsonDeque(std::deque<size_t> &arr)
{
	if (arr.size() <= 1)
		return;

	// make pair
	std::deque<pair> pairs;
	makePairs(arr, pairs);

	// flag and store leftover
	int left = -1;
	if (arr.size() % 2)
		left = arr.back();

	// sort pairs based on winner
	std::sort(pairs.begin(), pairs.end(), compareByBig);

	// storing winner among the pair
	std::deque<size_t> winner;
	for (size_t i = 0; i < pairs.size(); i++)
		winner.push_back(pairs[i].big);

	// recursively find the ultimate winner
	fordJohnsonDeque(winner);

	std::deque<size_t> result = winner;

	std::deque<size_t> loser;
	for (size_t i = 0; i < pairs.size(); i++)
		loser.push_back(pairs[i].small);

	std::deque<size_t> jsSeq = jacobsthal<std::deque<size_t> >(loser.size());
	for (size_t i = 0; i < jsSeq.size(); i++)
	{
		size_t idx = jsSeq[i] - 1;
		if (idx >= loser.size())
			continue;
		size_t value = loser[idx];
		std::deque<size_t>::iterator pos =
			binarySearchInsert(result, value);
		result.insert(pos, value);
	}

	for (size_t i = 0; i < loser.size(); i++)
	{
		size_t value = loser[i];
		if (std::find(result.begin(), result.end(), value) != result.end())
			continue;
		std::deque<size_t>::iterator pos =
			binarySearchInsert(result, value);
		result.insert(pos, value);
	}

	if (left != -1)
	{
		std::deque<size_t>::iterator pos =
			binarySearchInsert(result, left);
		result.insert(pos, left);
	}
	arr = result;
}

void PmergeMe::process_input()
{
	std::cout << "Before: ";
	printing(_vec);

	clock_t start = clock();
	fordJohnsonVector(_vec);
	clock_t end = clock();

	double vec_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	fordJohnsonDeque(_deq);
	end = clock();

	double deq_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	printing(_deq);

	std::cout << "Time to process a range of "
			  << _vec.size()
			  << " elements with std::vector : "
			  << vec_time << " us" << std::endl;

	std::cout << "Time to process a range of "
			  << _deq.size()
			  << " elements with std::deque : "
			  << deq_time << " us" << std::endl;
}
