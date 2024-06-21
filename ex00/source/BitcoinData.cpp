/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:13:09 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/19 14:41:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinData.hpp"

BitcoinData::~BitcoinData()
{
}

BitcoinData::BitcoinData(char const* filePath)
    : ADataFile(filePath)
{
    separator_char = ',';
    try
    {
        loadFromFile();
        if (data_size == 0)
            throw (std::runtime_error("No data found"));
    }
    catch (const std::runtime_error&)
    {
        throw;
    }
}

float BitcoinData::getExchangeRate(Date& date) const
{
    std::map<Date*, float>::const_iterator it = data.lower_bound(&date);

    if (it != data.end() && it->first == &date)
    {
        return it->second;
    }
    else if (it != data.begin())
    {
        --it;
        return it->second;
    }
    else
    {
        throw std::runtime_error("Error: no exchange rate found for the given date");
    }
}
