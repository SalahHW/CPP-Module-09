/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:08:08 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/25 00:49:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinData const& bitcoinData, UserInput const& userInput)
{
    std::map<Date*, float> bitcoin_data = bitcoinData.getData();
    std::map<Date*, float> user_input = userInput.getData();
    std::map<Date*, float>::iterator it;

    if (!user_input.empty())
        it = user_input.begin();
    while (it != user_input.end())
    {
        if (it->first->isValid())
            std::cout << *it->first << " => " << it->second << bitcoinData.getExchangeRate(*it->first) << std::endl;
        else
            std::cout << "Error: bad input => " << *it->first << std::endl;
        ++it;
    }
}
