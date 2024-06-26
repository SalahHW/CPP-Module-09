/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:26:25 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/26 14:39:10 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool utils::isWhiteSpace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')
		return (true);
	return (false);
}

std::string utils::trimWhitespace(const std::string& str)
{
	std::string::size_type first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
	{
		return "";
	}
	std::string::size_type last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, (last - first + 1));
}

float utils::strtof(std::string const &str)
{
	errno = 0;
	char *endptr = NULL;
	if (str.empty())
		throw std::runtime_error("Error while converting string to float");

	float value = std::strtof(str.c_str(), &endptr);
	if (errno == ERANGE)
		throw std::runtime_error("Error while converting string to float");
	if (*endptr != '\0')
		throw std::runtime_error("Error while converting string to float");
	return value;
}
