/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:08:08 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 16:37:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(ADataFile const &bitcoinData, ADataFile const &userInput)
{
	std::map<Date, float> bitcoin_data = bitcoinData.getData();
	std::map<Date, float> user_input = userInput.getData();
	std::map<Date, float>::iterator it;
	
	if (!user_input.empty())
		it = user_input.begin();
	while (it != user_input.end())
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}