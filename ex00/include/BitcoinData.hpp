/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinData.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:47:15 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/23 09:22:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ADataFile.hpp"
#include "Date.hpp"
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

class Date;

class BitcoinData : public ADataFile
{
public:
    ~BitcoinData();
    BitcoinData(char const *filePath);
    
    float getExchangeRate(const Date &date) const;
    
private:
    BitcoinData();
    BitcoinData(const BitcoinData &other);
    BitcoinData &operator=(const BitcoinData &other);
};