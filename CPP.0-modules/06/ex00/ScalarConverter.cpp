/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:08:11 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/23 18:01:37 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void)copy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) { (void)copy; return *this; }

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& str)
{
	char c = str[0];
	int i = strtod(str.c_str(), NULL);
	float f = static_cast<float>(strtod(str.c_str(), NULL));
	double d = strtod(str.c_str(), NULL);

	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (i == atol(str.c_str()))
		std::cout << i << std::endl;
	else
		std::cout << "out of scope" << std::endl;

	std::cout << "float: ";
	if (str == "-inff" || str == "+inff" || str == "nanf")
		std::cout << str << std::endl;
	else
		std::cout << f << "f" << std::endl;

	std::cout << "double: ";
	if (str == "-inf" || str == "+inf" || str == "nan")
		std::cout << str << std::endl;
	else
		std::cout << d << std::endl;
}
