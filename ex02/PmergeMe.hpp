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

        void fordJohnsonVector(std::vector<size_t>& arr);
        void fordJohnsonDeque(std::deque<size_t>& arr);

        PmergeMe();
        PmergeMe(const PmergeMe &);
        PmergeMe &operator=(const PmergeMe &);

    public:
        PmergeMe(char **av);
        ~PmergeMe();

        void process_input();
};

#endif