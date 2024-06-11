/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:41:43 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/08 06:35:33 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "BitcoinData.hpp"
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
	(void) argv;
	BitcoinData data(dataFilePath.c_str());
	Date test("2022-03-28");
	std::cout << data.getExchangeRate(test) << std::endl;
	return (0);
}