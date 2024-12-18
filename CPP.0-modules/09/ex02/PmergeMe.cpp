/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:30:11 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/18 18:20:30 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: _changeme("")
{}

PmergeMe::PmergeMe(const PmergeMe & copy)
	: _changeme(copy._changeme)
{}

PmergeMe & PmergeMe::operator=(const PmergeMe & copy)
{
	if (this != &copy)
	{
		_changeme = copy._changeme;
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
		for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		{
			if (*it == value)
				throw DuplicateValue();
		}
		_vec.push_back(value);
	}
}

void PmergeMe::run(const std::string &arg)
{
	try
	{
		parse(arg);
		for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
			std::cout << *it << " " << std::endl;
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
