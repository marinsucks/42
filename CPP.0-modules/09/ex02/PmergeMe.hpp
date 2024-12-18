/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:48:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/18 18:19:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <sstream>
#include <exception>

#define UINT_MAX 4294967295

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_list;
		std::string			_changeme;

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
