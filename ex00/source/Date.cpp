/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 05:00:40 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/26 20:03:04 by sbouheni         ###   ########.fr       */
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
	: input_date(date)
{
	processDate(date);
}

std::string const &Date::getDate() const
{
	return (this->input_date);
}

int Date::getYear() const
{
	return (this->year);
}

int Date::getMonth() const
{
	return (this->month);
}

int Date::getDay() const
{
	return (this->day);
}

bool Date::isValid() const
{
	return (is_valid);
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

bool Date::operator<=(Date const &other) const
{
	return (*this < other || *this == other);
}

bool Date::operator>(Date const &other) const
{
	if (*this < other || *this == other)
		return (false);
	return (true);
}

void Date::processDate(std::string const &date)
{
	try
	{
		validDate(date);
		convertDate(date);
		validDate();
		is_valid = true;
	}
	catch (const std::exception &e)
	{
		is_valid = false;
	}
}

void Date::validDate(std::string const &date)
{
	if (date.size() != 10)
		throw std::exception();
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw std::exception();
		}
		else if (date[i] < '0' || date[i] > '9')
			throw std::exception();
	}
}

void Date::validDate()
{
	if (year < 0 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31)
		throw std::exception();
}

void Date::convertDate(std::string const &date)
{
	std::string year_str;
	std::string month_str;
	std::string day_str;
	std::string::size_type first_separator = date.find('-');
	std::string::size_type second_separator = date.find('-', first_separator + 1);

	if (first_separator == std::string::npos || second_separator == std::string::npos)
		throw std::exception();
	year_str = date.substr(0, first_separator);
	month_str = date.substr(first_separator + 1, second_separator - first_separator - 1);
	day_str = date.substr(second_separator + 1);

	try
	{
		year = atoi(year_str.c_str());
		month = atoi(month_str.c_str());
		day = atoi(day_str.c_str());
	}
	catch (const std::exception &e)
	{
		throw std::exception();
	}
}

std::ostream &operator<<(std::ostream &os, Date const &date)
{
	os << date.getDate();
	return (os);
}