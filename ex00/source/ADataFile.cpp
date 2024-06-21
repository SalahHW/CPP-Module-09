/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADataFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:04:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/19 14:54:22 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ADataFile.hpp"

ADataFile::~ADataFile()
{
    std::map<Date*, float>::iterator it = data.begin();
    while (it != data.end())
    {
        delete it->first;
        ++it;
    }
}

ADataFile::ADataFile(char const* filePath)
    : filePath(filePath)
{
    data_size = 0;
    separator_char = ',';
}

std::map<Date*, float> ADataFile::getData() const
{
    return (data);
}

size_t ADataFile::getDataSize() const
{
    return (data_size);
}

void ADataFile::processLine(std::string const& line)
{
    std::string::size_type separator = line.find(separator_char);

    if (separator == std::string::npos)
        return;
    std::string date = line.substr(0, separator);
    std::string value = line.substr(separator + 1);
    addEntry(date, value);
}

void ADataFile::loadFromFile()
{
    std::ifstream data_file(filePath);
    std::string line;

    if (!data_file.is_open())
        throw std::runtime_error("Error while opening file");
    while (getline(data_file, line))
        processLine(line);
}

void ADataFile::addEntry(std::string const& date_str, std::string const& value_str)
{
    try
    {
        float value;
        Date* date = new Date(date_str);
        value = strtof(value_str.c_str(), NULL);
        data[date] = value;
        data_size++;
    }
    catch (const std::exception& e)
    {
        return;
    }
}
