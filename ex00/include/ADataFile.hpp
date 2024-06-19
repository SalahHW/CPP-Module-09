/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ADataFile.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:07:04 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/19 14:38:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <Date.hpp>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

class ADataFile
{
public:
	virtual ~ADataFile();
	ADataFile(char const *filePath);

	std::map<Date *, float> getData() const;
	size_t getDataSize() const;

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