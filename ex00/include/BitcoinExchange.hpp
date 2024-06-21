/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:42:25 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 16:36:35 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "BitcoinData.hpp"
#include "UserInput.hpp"
#include <iostream>
#include <map>

class BitcoinExchange
{
public:
    ~BitcoinExchange();
    BitcoinExchange(BitcoinData const &bitcoinData, UserInput const &userInput);

private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
};