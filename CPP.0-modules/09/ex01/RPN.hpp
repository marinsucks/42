/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:14:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/18 17:48:22 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <exception>
#include <cstdlib>
#include <sstream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class RPN
{
	private:
		std::string _str;
		std::stack <int> _stack;
		
		bool isOperator(const std::string & str) const;
		bool isNumber(const std::string & str) const;
		void parse();
		int calculate(char op);
		void solve();

	public:
		RPN();
		RPN(const RPN & copy);
		RPN & operator=(const RPN & copy);
		~RPN();

		void run(std::string arg);

		class TooManyOperands : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class TooManyOperators : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidCharacter : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class DivisionByZero : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class IntegerOverflow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class EmptyInputString : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
