/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:14:09 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/17 17:42:08 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map <std::string, double> _data;
		char _fs;
		std::string _filepath;
		size_t	_current_line;

		void checkFormat(std::string line);
		void checkDate(std::string date);
		void parseData();

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & copy);
		BitcoinExchange & operator=(const BitcoinExchange & copy);
		~BitcoinExchange();

		void run(std::string filename);

		class InvalidFile : public std::exception
		{		
			public:	
				const char * what() const throw();
		};
		class InvalidFormat : public std::exception
		{		
			public:
				const char * what() const throw();
		};
		class InvalidDate : public std::exception
		{	
			public:
				const char * what() const throw();
		};
		class InvalidValue : public std::exception
		{	
			public:
				const char * what() const throw();
		};
};
