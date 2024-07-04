/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:49:56 by sbouheni          #+#    #+#             */
/*   Updated: 2024/07/05 00:11:21 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cerrno>
#include <climits>

class PmergeMe
{
public:
	~PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);

	PmergeMe(int argc, char **argv);

	void printVector() const;
	void printList() const;

private:
	PmergeMe();

	void extractNumbers(int argc, char **argv);
	bool isValidNumber(char *str) const;

	std::vector<int> dataVector;
	std::list<int> dataList;
};