/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:09:07 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/31 16:34:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
	: _max(0)
{}

Span::Span(int N)
	: _max(N)
{}

Span::Span(const Span& copy)
{
	if (this == &copy)
		return ;

	_max = copy._max;
	_nums = copy._nums;
}

Span& Span::operator=(const Span& copy)
{
	if (this == &copy)
		return *this;

	_max = copy._max;
	_nums = copy._nums;

	return *this;
}

Span::~Span() {}


void	Span::addNumber(int num)
{
	if (_nums.size() >= _max)
		throw SpanFull();
	_nums.insert(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_nums.size() + std::distance(begin, end) > _max)
		throw SpanFull();
	_nums.insert(begin, end);
}

int		Span::shortestSpan()
{
	if (_nums.size() < 2)
		throw SpanEmpty();

	int span = (*std::min_element(_nums.begin(), _nums.end()) - *std::max_element(_nums.begin(), _nums.end()));
	if (span < 0)
		span *= -1;

	std::set<int>::iterator it = _nums.begin();
	for (unsigned long i = 0; i < _nums.size() - 1; i++)
	{
		int curr = *it;
		int next = *(++it);
		if (next - curr < span)
			span = next - curr;
		if (span == 0)
			return (0);
	}

	return (span);
}

int		Span::longestSpan()
{
	if (_nums.size() < 2)
		throw SpanEmpty();

	int min = *std::min_element(_nums.begin(), _nums.end());
	int max = *std::max_element(_nums.begin(), _nums.end());

	if (max < min)
		return (min - max);
	else
		return (max - min);
}


const char *	Span::SpanFull::what() const throw()
{
	return "Span is full";
}

const char *	Span::SpanEmpty::what() const throw()
{
	return "Span is empty";
}

std::set<int>	Span::getNums() const
{
	return _nums;
}

std::ostream &operator<<(std::ostream & os, Span const & rhs)
{
	std::set<int> nums = rhs.getNums();
	std::set<int>::iterator it = nums.begin();
	for (unsigned long i = 0; i < nums.size(); i++)
	{
		os << *it;
		if (i < nums.size() - 1)
			os << ", ";
		it++;
	}
	return os;
}
