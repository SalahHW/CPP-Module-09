/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:30:44 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/14 03:16:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <string>
#include <cstdlib>

class Date
{
public:
	~Date();
	Date(Date const &other);
	Date &operator=(Date const &other);
	Date(std::string const &date);

	std::string const & getDate() const;
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	bool operator<(Date const &other) const;
	bool operator==(Date const &other) const;

private:
	Date();

	const std::string input_date;
	int year;
	int month;
	int day;

	void processDate(std::string const &date);
};

std::ostream &operator<<(std::ostream &os, Date const &date);