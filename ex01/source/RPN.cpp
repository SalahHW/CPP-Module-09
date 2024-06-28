/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:07:47 by sbouheni          #+#    #+#             */
/*   Updated: 2024/06/28 16:57:08 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN() {}

int RPN::calculate(const std::string &input)
{
	std::stack<int> stack;
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
		{
			if (stack.size() < 2)
				throw(std::runtime_error("Error: Not enough operands for operators"));
			int operand2 = stack.top();
			stack.pop();
			int operand1 = stack.top();
			stack.pop();
			int result = performOperation(operand1, operand2, token);
			stack.push(result);
		}
		else
		{
			if (token.find_first_not_of("0123456789") != std::string::npos)
				throw(std::runtime_error("Error: Invalid token"));
			stack.push(std::atoi(token.c_str()));
		}
	}
	if (stack.size() != 1)
	{
		throw(std::runtime_error("Error: Invalid RPN expression"));
		return 0;
	}
	return stack.top();
}

bool RPN::isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::performOperation(int operand1, int operand2, const std::string &operatorToken)
{
	if (operatorToken == "+")
		return operand1 + operand2;
	if (operatorToken == "-")
		return operand1 - operand2;
	if (operatorToken == "*")
		return operand1 * operand2;
	if (operatorToken == "/")
	{
		if (operand2 == 0)
			throw(std::runtime_error("Error: Division by zero"));
		return operand1 / operand2;
	}
	return 0;
}