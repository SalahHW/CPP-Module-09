/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 05:00:40 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/08 06:30:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::~Date() {}

Date::Date(Date const &other)
{
	*this = other;
}

Date &Date::operator=(Date const &other)
{
	if (this != &other)
	{
		year = other.year;
		month = other.month;
		day = other.day;
	}
	return (*this);
}

Date::Date(std::string const &date)
{
	std::string year_str;
	std::string month_str;
	std::string day_str;
	std::string::size_type first_separator = date.find('-');
	std::string::size_type second_separator = date.find('-', first_separator + 1);

	if (first_separator == std::string::npos || second_separator == std::string::npos)
		throw std::runtime_error("Invalid format");
	year_str = date.substr(0, first_separator);
	month_str = date.substr(first_separator + 1, second_separator - first_separator - 1);
	day_str = date.substr(second_separator + 1);

	year = atoi(year_str.c_str());
	month = atoi(month_str.c_str());
	day = atoi(day_str.c_str());
}

int Date::getYear() const
{
	return (year);
}

int Date::getMonth() const
{
	return (month);
}

int Date::getDay() const
{
	return (day);
}

bool Date::operator<(Date const &other) const
{
	if (year != other.year)
        return year < other.year;
	else if (month != other.month)
        return month < other.month;
    else
        return day < other.day;
}

bool Date::operator==(Date const &other) const
{
	return (year == other.year && month == other.month && day == other.day);
}