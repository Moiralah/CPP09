/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 08:55:47 by huidris           #+#    #+#             */
/*   Updated: 2026/03/16 23:18:38 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

static bool check_date(const std::string date)
{
	struct tm tm;
	memset(&tm, 0, sizeof(tm));

	char *righttime = strptime(date.c_str(), "%Y-%m-%d", &tm);

	if (righttime == NULL || *righttime != '\0')
		return false;
	return true;
}

static std::string trim(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return str.substr(start, end - start + 1);
}

int BitcoinExchange::loadDB(const std::string &database)
{
	std::string read;
	std::ifstream file(database.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	if (!getline(file, read))
	{
		std::cerr << "Error: empty file." << std::endl;
		return 1;
	}

	if (read != "date,exchange_rate")
	{
		std::cerr << "Error: invalid database header." << std::endl;
		return 1;
	}

	while (getline(file, read))
	{
		std::stringstream ss(read);
		std::string date;
		std::string value;

		if (read.find(',') == std::string::npos)
		{
			std::cerr << "Error: bad input => " << read << std::endl;
			continue;
		}
		getline(ss, date, ',');
		date = trim(date);
		if (!check_date(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		getline(ss, value);
		const float val = std::atof(value.c_str());
		_data[date] = val;
	}
	return 0;
}

int BitcoinExchange::processInput(const std::string &input)
{
	std::string read;
	std::ifstream file(input.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	if (!getline(file, read))
	{
		std::cerr << "Error: empty file." << std::endl;
		return 1;
	}

	if(read != "date | value")
	{
		std::cerr << "Error: invalid database header." << std::endl;
		return 1;
	}

	while (getline(file, read))
	{
		std::stringstream ss(read);
		std::string date;
		std::string value;

		if (read.find('|') == std::string::npos)
		{
			std::cerr << "Error: bad input => " << read << std::endl;
			continue;
		}
		getline(ss, date, '|');
		date = trim(date);
		if (!check_date(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		getline(ss, value);
		const float val = std::atof(value.c_str());
		if (val <= 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (val >= 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = getRate(date);
		if (rate == -1)
			continue;

		std::cout << date << " => " << val << " = " << val * rate << std::endl;
	}
	return 0;
}

float BitcoinExchange::getRate(const std::string &date)
{
	std::map<std::string, float>::iterator it = _data.lower_bound(date);

	if (it == _data.end() || it->first != date)
	{
		if (it != _data.begin())
			--it;
	}
	if (it == _data.begin() && it->first != date)
	{
		std::cerr << "Error: no earlier data" << std::endl;
		return -1;
	}
	return it->second;
}
