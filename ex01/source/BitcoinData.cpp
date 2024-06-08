/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinData.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:13:09 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/08 06:31:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinData.hpp"

BitcoinData::~BitcoinData() {}

BitcoinData::BitcoinData(char const *filePath)
{
    try
    {
        loadFromFile(filePath);
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

float BitcoinData::getExchangeRate(Date const &date) const
{
    std::map<Date, float>::const_iterator it = data.lower_bound(date);

    if (it != data.end() && it->first == date)
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
        throw std::runtime_error("Error: no exchange rate found for the given date or earlier.");
    }
}

void BitcoinData::loadFromFile(char const *filePath)
{
    std::ifstream data_file(filePath);
    std::string line;

    if (!data_file.is_open())
        throw std::runtime_error("Error while opening file");
    while (getline(data_file, line))
        processLine(line);
}

void BitcoinData::processLine(std::string const &line)
{
    std::string::size_type separator = line.find(',');

    if (separator == std::string::npos)
        return;
    std::string date = line.substr(0, separator);
    std::string value = line.substr(separator + 1);
    addEntry(date, value);
}

void BitcoinData::addEntry(std::string const &date_str, std::string const &value_str)
{
    try
    {
        float value;
        Date date(date_str);
        value = strtof(value_str.c_str(), NULL);
        data[date] = value;
    }
    catch (const std::exception &e)
    {
        return;
    }
}