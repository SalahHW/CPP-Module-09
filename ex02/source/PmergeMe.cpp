/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:53:32 by sbouheni          #+#    #+#             */
/*   Updated: 2024/07/04 17:00:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	this->dataVector = other.dataVector;
	this->dataList = other.dataList;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		this->dataVector = other.dataVector;
		this->dataList = other.dataList;
	}
	return (*this);
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	extractNumbers(argc, argv);
}

void PmergeMe::printVector() const
{
	std::vector<int>::const_iterator it = dataVector.begin();

	if (it != dataVector.end())
		std::cout << "vector: [";
	while (it != dataVector.end())
	{
		std::cout << *it;
		++it;
		if (it != dataVector.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void PmergeMe::printList() const
{
	std::list<int>::const_iterator it = dataList.begin();

	if (it != dataList.end())
		std::cout << "list: [";
	while (it != dataList.end())
	{
		std::cout << *it;
		++it;
		if (it != dataList.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void PmergeMe::extractNumbers(int argc, char **argv)
{
	int num;
	for (int i = 1; i < argc; i++)
	{
		//TODO : check numbers before atoi;
		num = std::atoi(argv[i]);
		dataVector.push_back(num);
		dataList.push_back(num);
	}
	//
	printVector();
	printList();
}