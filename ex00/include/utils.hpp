/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:26:34 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/26 20:02:35 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <string>
#include <cerrno>
#include <cstdlib>

namespace utils
{
	bool isWhiteSpace(char c);
	std::string trimWhitespace(const std::string &str);
	float strtof(std::string const &str);
}