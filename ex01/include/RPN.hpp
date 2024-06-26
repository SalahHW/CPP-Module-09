/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:07:39 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/27 19:27:16 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

class RPN
{
public:
	~RPN();
	static int calculate(const std::string &input);

private:
	RPN();
	RPN(RPN const &other);
	RPN &operator=(RPN const &other);

	static bool isOperator(const std::string &token);
	static int performOperation(int operand1, int operand2, const std::string &operatorToken);
};