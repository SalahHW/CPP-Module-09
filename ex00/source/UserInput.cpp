/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInput.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:59 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 16:12:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInput.hpp"

UserInput::~UserInput() {}

UserInput::UserInput(char const *filePath)
	: ADataFile(filePath)
{
	try
	{
		loadFromFile();
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void UserInput::processLine(std::string const &line)
{
	std::string::size_type separator = line.find('|');

	if (separator == std::string::npos)
		return;
	std::string date = line.substr(0, separator);
	std::string value = line.substr(separator + 1);
	addEntry(date, value);
}