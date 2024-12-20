/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:30:11 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/20 17:40:35 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe & copy)
	: _vec(copy._vec), _list(copy._list)
{}

PmergeMe & PmergeMe::operator=(const PmergeMe & copy)
{
	if (this == &copy)
	{
		_vec = copy._vec;
		_list = copy._list;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

bool PmergeMe::isPositiveInt(const std::string & token) const
{
	if (token.empty())
		return false;

	for (size_t i = 0; i < token.size(); ++i)
	{
		if (i == 0 && (token[i] == '+'))
			continue;
		if (!std::isdigit(token[i]))
			return false;
	}

	long long int value = atoll(token.c_str());
	if (value < 0 || value > UINT_MAX)
		return false;

	return true;
}

void PmergeMe::parse(const std::string &arg)
{
	if (arg.empty())
		throw EmptyInputString();
	
	std::istringstream iss(arg);
	std::string token;
	int	value;
	
	while (iss >> token)
	{
		if (!isPositiveInt(token))
			throw InvalidCharacter();
		value = atoi(token.c_str());
		if (_vec.contains(value))
			throw DuplicateValue();
		_vec.push_back(value);
		_list.push_back(value);
	}
}


void PmergeMe::run(const std::string &arg)
{
	try
	{
		parse(arg);

		std::cout << "Before [vector]:\t";
		_vec.print();
		std::cout << "Before [list]:\t";
		_list.print();

		_vec_time = _vec.sort();
		std::cout << "After [vector]:\t";
		_vec.print();

		_list_time = _list.sort();
		std::cout << "After [list]:\t";
		_list.print();

		if (!_vec.isSorted())
			throw std::runtime_error("Vector is not sorted");
		if (!_list.isSorted())
			throw std::runtime_error("List is not sorted");


		std::cout << std::endl;

		std::cout << "Time to process a range of\t" << _vec.size() << " elements" 
			<< " with std::vector:\t" << _vec_time << " ms" << std::endl;
		std::cout << "Time to process a range of\t" << _list.size() << " elements" 
			<< " with std::list:\t" << _list_time << " ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

const char *PmergeMe::InvalidCharacter::what() const throw()
{
	return "invalid character detected";
}

const char *PmergeMe::DuplicateValue::what() const throw()
{
	return "duplicate value detected";
}

const char* PmergeMe::EmptyInputString::what() const throw()
{
	return "empty input string";
}
