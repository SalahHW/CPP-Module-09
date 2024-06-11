/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 03:30:44 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/08 06:29:31 by sbouheni         ###   ########.fr       */
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

	int getYear() const;
	int getMonth() const;
	int getDay() const;

	bool operator<(Date const &other) const;
	bool operator==(Date const &other) const;

private:
	Date();

	int year;
	int month;
	int day;
};