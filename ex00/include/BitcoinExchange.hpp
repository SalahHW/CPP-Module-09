/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:42:25 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 16:26:09 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ADataFile.hpp"
#include <map>

class BitcoinExchange
{
public:
    ~BitcoinExchange();
    BitcoinExchange(ADataFile const &bitcoinData, ADataFile const &userInput);

private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
};