/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:49:56 by sbouheni          #+#    #+#             */
/*   Updated: 2024/07/04 16:52:50 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>

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
	std::vector<int> dataVector;
	std::list<int> dataList;
};