/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinData.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:47:15 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/08 06:25:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Date.hpp"
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

class Date;

class BitcoinData
{
public:
    ~BitcoinData();
    BitcoinData(char const *filePath);
    
    float getExchangeRate(Date const &date) const;
private:
    BitcoinData();
    BitcoinData(const BitcoinData &other);
    BitcoinData &operator=(const BitcoinData &other);

    void    loadFromFile(const char *filePath);
    void    processLine(std::string const &line);
    void    addEntry(std::string const &date, std::string const &value);

    std::map<Date, float> data;
};