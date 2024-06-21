/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInput.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:59 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 17:24:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInput.hpp"

UserInput::~UserInput()
{
}

UserInput::UserInput(char const* filePath)
    : ADataFile(filePath)
{
    separator_char = '|';
    try
    {
        loadFromFile();
        if (data_size == 0)
            throw (std::runtime_error("No data found"));
    }
    catch (const std::runtime_error&)
    {
        throw;
    }
}
