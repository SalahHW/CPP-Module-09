/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:41:43 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/25 00:26:46 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "BitcoinData.hpp"
#include "UserInput.hpp"
#include "Date.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string dataFilePath = "data.csv";
	if (argc != 2)
	{
		std::cerr << "Usage: " << "./btc <filename>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinData data(dataFilePath.c_str());
		UserInput input(argv[1]);
		BitcoinExchange(data, input);
		Date test("2009-01-01");
		// std::cout << data;
		// data.getExchangeRate(test);
		// std::cout << "=" << test << " = " << data.getExchangeRate(test) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}