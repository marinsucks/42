/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:48:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/20 15:24:30 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <exception>

#include "AContainer.hpp"
#include "Vector.hpp"
#include "List.hpp"

#define UINT_MAX 4294967295

class PmergeMe
{
	private:
		Vector	_vec;
		List		_list;
		double	_vec_time;
		double	_list_time;

		bool isPositiveInt(const std::string & str) const;
		void parse(const std::string &arg);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe & copy);
		PmergeMe & operator=(const PmergeMe & copy);
		~PmergeMe();

		void run(const std::string &arg);

		class InvalidCharacter : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class DuplicateValue : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class EmptyInputString : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

