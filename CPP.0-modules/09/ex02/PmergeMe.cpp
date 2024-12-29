/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:30:11 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/29 14:16:57 by mbecker          ###   ########.fr       */
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

void PmergeMe::checkPositiveInt(const std::string & token) const
{
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (i == 0 && (token[i] == '+'))
			continue;
		if (!std::isdigit(token[i]))
			throw InvalidCharacter();
	}

	long long int value = atoll(token.c_str());
	if (value < 0 || value > MACRO_UINT_MAX)
		throw OutOfIntBounds();
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
		checkPositiveInt(token);
		value = atoi(token.c_str());
		if (_vec.contains(value))
			throw DuplicateValue();
		_vec.push_back(value);
		_list.push_back(value);
	}
	if (_vec.size() == 0)
		throw EmptyInputString();
}


void PmergeMe::run(const std::string &arg)
{
	try
	{
		parse(arg);

		std::cout << "Before:\t" << LGREY;
		_vec.print();
		std::cout << NC;

		_vec_time = _vec.sort();
		if (!_vec.isSorted())
			throw std::runtime_error("Vector is not sorted");

		_list_time = _list.sort();
		if (!_list.isSorted())
			throw std::runtime_error("List is not sorted");

		std::cout << "After:\t" << LGREY;
		_vec.print();
		std::cout << NC << std::endl;

		std::cout << "Time to process a range of " << LYELLOW << _vec.size() << NC << " elements" 
			<< " with " << LMAGENTA << "std::vector" << NC << ": " << RED << _vec_time << " ms" << NC << std::endl;
		std::cout << "Time to process a range of " << LYELLOW << _list.size() << NC << " elements" 
			<< " with " << LCYAN << "std::list" << NC << ":   " << RED << _list_time << " ms" << NC << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << ". Exiting program." << std::endl;
	}
}

const char *PmergeMe::InvalidCharacter::what() const throw()
{
	return "invalid character detected";
}

const char *PmergeMe::OutOfIntBounds::what() const throw()
{
	return "number out of unsigned integer bounds detected";
}

const char *PmergeMe::DuplicateValue::what() const throw()
{
	return "duplicate value detected";
}

const char* PmergeMe::EmptyInputString::what() const throw()
{
	return "empty input string";
}
