/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 07:10:14 by huidris           #+#    #+#             */
/*   Updated: 2026/03/16 21:27:25 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <sstream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		BitcoinExchange(BitcoinExchange &);
		BitcoinExchange &operator=(BitcoinExchange &);

	public:
		BitcoinExchange();
		~BitcoinExchange();


		int loadDB(const std::string &);
		int processInput(const std::string &);
		float getRate(const std::string &date);

};

#endif
