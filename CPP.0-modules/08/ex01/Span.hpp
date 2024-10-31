/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:45:09 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/31 16:30:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "STL.hpp"

class Span
{
	private:
		unsigned int	_max;
		std::set<int>	_nums;
	public:
		Span();
		Span(int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		
		void	addNumber(int num);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

		class	SpanFull : public std::exception { public: const char *what() const throw(); };
		class	SpanEmpty : public std::exception { public: const char *what() const throw(); };

		std::set<int>	getNums() const;
};

std::ostream &operator<<(std::ostream & os, Span const & rhs);
