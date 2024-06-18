/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADataFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:04:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 16:10:58 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ADataFile.hpp"

ADataFile::~ADataFile() {}

ADataFile::ADataFile(char const *filePath)
	: filePath(filePath)
{
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

void ADataFile::addEntry(std::string const &date_str, std::string const &value_str)
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