/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:14:18 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/18 16:32:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN & copy)
	: _str(copy._str), _stack(copy._stack)
{}

RPN & RPN::operator=(const RPN & copy)
{
	if (this != &copy)
	{
		_str = copy._str;
		_stack = copy._stack;
	}
	return *this;
}

RPN::~RPN()
{}

bool RPN::isOperator(const std::string & str) const
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

bool RPN::isNumber(const std::string & str) const
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void RPN::parse()
{
	std::istringstream iss(_str);
	std::string token;

	while (iss >> token)
	{
		if (!isNumber(token) && !isOperator(token))
			throw InvalidCharacter();
	}
}

int RPN::calculate(char op)
{
	long lhs;
	long rhs;
	long result;
	
	rhs = _stack.top();
	_stack.pop();
	lhs = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '+':
			result = lhs + rhs;
			break;
		case '-':
			result = lhs - rhs;
			break;
		case '*':
			result = lhs * rhs;
			break;
		case '/':
			if (rhs == 0)
				throw DivisionByZero();
			result = lhs / rhs;
			break;
	}
	
	if (result > INT_MAX || result < INT_MIN)
		throw IntegerOverflow();
	return result;
}

void RPN::solve()
{
	std::string tkn;
	std::istringstream iss(_str);
	
	while (iss >> tkn)
	{
		while (!isOperator(tkn))
		{
			_stack.push(atoi(tkn.c_str()));
			if (iss.eof())
				throw TooManyOperands();
			iss >> tkn;
		}
		if (_stack.size() < 2)
			throw TooManyOperators();
		_stack.push(calculate(tkn[0]));
	}
	if (_stack.size() != 1)
		throw TooManyOperands();
}

void RPN::run(std::string arg)
{
	_str = arg;
	try
	{
		parse();
		solve();
		std::cout << _stack.top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

const char* RPN::TooManyOperands::what() const throw()
{
	return "too many operands";
}

const char* RPN::TooManyOperators::what() const throw()
{
	return "too many operators";
}

const char* RPN::InvalidCharacter::what() const throw()
{
	return "invalid character detected";
}

const char* RPN::DivisionByZero::what() const throw()
{
	return "division by zero";
}

const char* RPN::IntegerOverflow::what() const throw()
{
	return "integer overflow";
}
