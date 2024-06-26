/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:08:08 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/26 19:21:43 sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinData const &bitcoinData, UserInput const &userInput)
{
    std::map<Date *, float> bitcoin_data = bitcoinData.getData();
    std::map<Date *, float> user_input = userInput.getData();
    std::map<Date *, float>::iterator it;
    float exchange_rate;

    if (!user_input.empty())
        it = user_input.begin();
    while (it != user_input.end())
    {
        if (it->first->isValid() && it->second >= 0 && it->second <= 1000)
        {
            try
            {
                std::cout << *it->first << " => "
                          << std::fixed << std::setprecision(3) << it->second << " = ";
                exchange_rate = bitcoinData.getExchangeRate(*it->first);
                std::cout << std::fixed << std::setprecision(2) << exchange_rate * it->second << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        else if (!it->first->isValid())
            std::cerr << "Error: bad input => " << *it->first << std::endl;
        else
        {
            if (it->second < 0)
                std::cerr << *it->first << " => " << "Error: negative value" << std::endl;
            else if (it->second > 1000)
                std::cerr << *it->first << " => " << "Error: value too high" << std::endl;
            else
                std::cerr << *it->first << " => " << "Error: bad value" << std::endl;
        }
        ++it;
    }
}
