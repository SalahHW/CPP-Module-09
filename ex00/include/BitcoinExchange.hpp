/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:42:25 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/08 05:25:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
public:
    ~BitcoinExchange();

private:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
};