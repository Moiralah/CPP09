/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 08:10:49 by huidris           #+#    #+#             */
/*   Updated: 2026/03/16 21:28:24 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Could not open file" << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	if (btc.loadDB("data.csv") == 1)
		return 1;
	if (btc.processInput(av[1]) == 1)
		return 1;
	return 0;
}
