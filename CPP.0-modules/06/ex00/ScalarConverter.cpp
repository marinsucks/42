/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:08:11 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/24 15:10:49 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) { (void)copy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) { (void)copy; return *this; }

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& str)
{
	double	d;
	if (str.size() == 1 && !isdigit(str[0]))
		d = str[0];
	else
		d = strtod(str.c_str(), NULL);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);

	std::cout << "char: ";
	if (!(d >= 0 && d <= 255))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (static_cast<double>(i) == d 
		||  (d >= 0 && (d >= i && d < i + 1))
		||  (d < 0 && (d <= i && d > i - 1)))
		std::cout << i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
