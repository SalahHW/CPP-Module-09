/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInput.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:54:41 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/18 15:59:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ADataFile.hpp"

class UserInput : public ADataFile
{
public:
	~UserInput();
	UserInput(char const *filePath);
	
private:
	UserInput();
	UserInput(UserInput const &other);
	UserInput &operator=(UserInput const &other);

	void processLine(std::string const &line);
};