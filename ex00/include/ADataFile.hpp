/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADataFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:07:04 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/26 14:55:52 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"
#include "Date.hpp"
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

class ADataFile
{
public:
	virtual ~ADataFile();
	ADataFile(char const *filePath);

	std::map<Date *, float> getData() const;
	size_t getDataSize() const;
	void printData() const;

private:
	ADataFile();
	ADataFile(ADataFile const &other);
	ADataFile &operator=(ADataFile const &other);

	void processLine(std::string const &line);

protected:
	void loadFromFile();
	void addEntry(std::string const &date_str, std::string const &value_str);

	char const *filePath;
	std::map<Date *, float> data;
	size_t data_size;
	char separator_char;
};