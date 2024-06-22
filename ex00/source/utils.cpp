//
// Created by salah on 22/06/24.
//

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
