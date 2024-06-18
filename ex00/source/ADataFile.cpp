/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADataFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:04:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 13:32:59 by sbouheni         ###   ########.fr       */
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