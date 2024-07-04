/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:49:56 by sbouheni          #+#    #+#             */
/*   Updated: 2024/07/05 01:08:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cerrno>
#include <climits>
#include <ctime>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class PmergeMe
{
public:
	~PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);

	PmergeMe(int argc, char **argv);

	void printVector() const;
	void printList() const;
	void merge(std::vector<int>::iterator left, std::vector<int>::iterator middle, std::vector<int>::iterator right);
	void merge(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right);
	void fordJohnsonSort(std::vector<int> &container, std::vector<int>::iterator left, std::vector<int>::iterator right);
	void fordJohnsonSort(std::list<int> &container, std::list<int>::iterator left, std::list<int>::iterator right);

private:
	PmergeMe();

	void extractNumbers(int argc, char **argv);
	bool isValidNumber(char *str) const;

	std::vector<int> dataVector;
	std::list<int> dataList;
};