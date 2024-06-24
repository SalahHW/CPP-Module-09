/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:13:09 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/25 00:35:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinData.hpp"

BitcoinData::~BitcoinData()
{
}

BitcoinData::BitcoinData(char const *filePath)
    : ADataFile(filePath)
{
    separator_char = ',';
    try
    {
        loadFromFile();
        if (data_size == 0)
            throw(std::runtime_error("No data found"));
    }
    catch (const std::runtime_error &)
    {
        throw;
    }
}

float BitcoinData::getExchangeRate(const Date &date) const
{
    std::map<Date *, float>::const_iterator it = data.begin();

    if (date < *it->first)
        throw std::runtime_error("No exchange rate found");

    float value = it->second;

    while (it != data.end())
    {
        if (date < *it->first)
            return (value);
        value = it->second;
        ++it;
    }
    return (value);
}
