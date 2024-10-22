/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:08:11 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/22 17:51:38 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void)copy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) { (void)copy; return *this; }

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& str)
{
	char c = static_cast<char>(str[0]);
	int i = atoi(str.c_str());
	float f = static_cast<float>(atof(str.c_str()));
	double d = atof(str.c_str());

	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
