/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:53:32 by sbouheni          #+#    #+#             */
/*   Updated: 2024/07/05 01:26:31 by sbouheni         ###   ########.fr       */
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
	std::cout << "Before: ";
	printVector();
	clock_t vectorStart = clock();
	fordJohnsonSort(dataVector, dataVector.begin(), dataVector.end());
	clock_t vectorEnd = clock();
	clock_t listStart = clock();
	fordJohnsonSort(dataList, dataList.begin(), dataList.end());
	clock_t listEnd = clock();

	double vectorTime = (double)(vectorEnd - vectorStart) * 1000 / CLOCKS_PER_SEC;
	double listTime = (double)(listEnd - listStart) * 1000 / CLOCKS_PER_SEC;
	
	std::cout << "After: ";
	printVector();
	std::cout << "Time to process a range of " << dataVector.size() << " elements with std::vector : " << vectorTime << "ms" << std::endl;
	std::cout << "Time to process a range of " << dataList.size() << " elements with std::list : " << listTime << "ms" << std::endl;
}

void PmergeMe::printVector() const
{
	std::vector<int>::const_iterator it = dataVector.begin();

	if (it != dataVector.end())
		std::cout << "[";
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
		std::cout << "[";
	while (it != dataList.end())
	{
		std::cout << *it;
		++it;
		if (it != dataList.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void PmergeMe::merge(std::vector<int>::iterator left, std::vector<int>::iterator middle, std::vector<int>::iterator right)
{
	std::vector<int> tmp;
	std::vector<int>::iterator it1 = left;
	std::vector<int>::iterator it2 = middle;
	while (it1 != middle && it2 != right)
	{
		if (*it1 < *it2)
		{
			tmp.push_back(*it1);
			++it1;
		}
		else
		{
			tmp.push_back(*it2);
			++it2;
		}
	}
	while (it1 != middle)
	{
		tmp.push_back(*it1);
		++it1;
	}
	while (it2 != right)
	{
		tmp.push_back(*it2);
		++it2;
	}
	it1 = left;
	it2 = tmp.begin();
	while (it1 != right)
	{
		*it1 = *it2;
		++it1;
		++it2;
	}
}

void PmergeMe::merge(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right)
{
	std::list<int> tmp;
	std::list<int>::iterator it1 = left;
	std::list<int>::iterator it2 = middle;
	while (it1 != middle && it2 != right)
	{
		if (*it1 < *it2)
		{
			tmp.push_back(*it1);
			++it1;
		}
		else
		{
			tmp.push_back(*it2);
			++it2;
		}
	}
	while (it1 != middle)
	{
		tmp.push_back(*it1);
		++it1;
	}
	while (it2 != right)
	{
		tmp.push_back(*it2);
		++it2;
	}
	it1 = left;
	it2 = tmp.begin();
	while (it1 != right)
	{
		*it1 = *it2;
		++it1;
		++it2;
	}
}

void PmergeMe::fordJohnsonSort(std::vector<int> &container, std::vector<int>::iterator left, std::vector<int>::iterator right)
{
	if (left == right || std::distance(left, right) == 1)
		return;
	std::vector<int>::iterator midle = left;
	std::advance(midle, std::distance(left, right) / 2);

	fordJohnsonSort(container, left, midle);
	fordJohnsonSort(container, midle, right);

	merge(left, midle, right);
}

void PmergeMe::fordJohnsonSort(std::list<int> &container, std::list<int>::iterator left, std::list<int>::iterator right)
{
	if (left == right || std::distance(left, right) == 1)
		return;
	std::list<int>::iterator midle = left;
	std::advance(midle, std::distance(left, right) / 2);

	fordJohnsonSort(container, left, midle);
	fordJohnsonSort(container, midle, right);

	merge(left, midle, right);
}

void PmergeMe::extractNumbers(int argc, char **argv)
{
	int num;
	for (int i = 1; i < argc; i++)
	{
		if (!isValidNumber(argv[i]))
			throw std::invalid_argument("Argument contains invalid number.");
		num = std::atoi(argv[i]);
		dataVector.push_back(num);
		dataList.push_back(num);
	}
}

bool PmergeMe::isValidNumber(char *str) const
{
	std::string number(str);
	long num;

	if (number.empty())
		return (false);
	for (size_t i = 0; i < number.size(); i++)
	{
		if (i == 0 && (number[i] == '-' || number[i] == '+'))
			continue;
		if (!std::isdigit(number[i]))
			return (false);
	}
	errno = 0;
	num = std::atol(str);
	if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
		return (false);
	return (true);
}