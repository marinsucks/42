/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:08:11 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/24 14:37:58 by mbecker          ###   ########.fr       */
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
	
	if ((!std::isdigit(c) && d == 0) 
		&& str != "nan"
		&& str != "inff" && str != "inf"  
		&& str != "-inff" && str != "-inf")
	{
		std::cout << "int: " << static_cast<int>(c) << std::endl; 
		std::cout << "float: "<< static_cast<float>(c) << "f" << std::endl; 
		std::cout << "double: "<< static_cast<double>(c) << std::endl;
		return ;
	}

	std::cout << "int: ";
	if (static_cast<double>(i) == d || (d >= i && d < i + 1))
		std::cout << i << std::endl;
	else
		std::cout << "out of scope" << std::endl;

	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
