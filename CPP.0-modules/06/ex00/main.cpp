/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:25:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/24 14:24:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iomanip>
#include "colors.hpp"

void	unit_test()
{
	std::string testint[] = {
	    "0", "1", "42", "-42", "2147483647", "-2147483648", 
	    "2147483648", "-2147483649"
	};

	for (size_t i = 0; i < sizeof(testint) / sizeof(testint[0]); i++)
	{
		std::cout << BLUE << testint[i] << NC << std::endl;
		ScalarConverter::convert(testint[i]);
		std::cout << std::endl;
	}
	std::cout << "---------------------------------\n" << std::endl;

	std::string testfloat[] = {
	    "0.0", "1.23", "-1.23", "42.0", "3.14159",
	    "3.4028235e38", "-3.4028235e38"
	};
	
	for (size_t i = 0; i < sizeof(testfloat) / sizeof(testfloat[0]); i++)
	{
		std::cout << BLUE << testfloat[i] << NC << std::endl;
		ScalarConverter::convert(testfloat[i]);
		std::cout << std::endl;
	}
	std::cout << "---------------------------------\n" << std::endl;

	std::string testdouble[] = {
		"1.7976931348623157e308", "-1.7976931348623157e308",
	    "NaN", "INF", "-INF", 
	    "1.8e308", "-1.8e308"
	};

	for (size_t i = 0; i < sizeof(testdouble) / sizeof(testdouble[0]); i++)
	{
		std::cout << BLUE << testdouble[i] << NC << std::endl;
		ScalarConverter::convert(testdouble[i]);
		std::cout << std::endl;
	}
	std::cout << "---------------------------------\n" << std::endl;

	std::string testchar[] = {
	    "a", "Z", "9", "!",
	    "\0", "\n", "\t"
	};

	for (size_t i = 0; i < sizeof(testchar) / sizeof(testchar[0]); i++)
	{
		std::cout << BLUE << testchar[i] << NC << std::endl;
		ScalarConverter::convert(testchar[i]);
		std::cout << std::endl;
	}
	std::cout << "---------------------------------\n" << std::endl;

	std::string testinvalid[] = {
	    "abc", "42abc", "NaN", "4.2e4xyz", 
	    "#", "@!", "12#34", 
	    "", "   ", 
	    "1.23.45", "12e34", "12.34.56"
	};

	for (size_t i = 0; i < sizeof(testinvalid) / sizeof(testinvalid[0]); i++)
	{
		std::cout << BLUE << testinvalid[i] << NC << std::endl;
		ScalarConverter::convert(testinvalid[i]);
		std::cout << std::endl;
	}
	std::cout << "---------------------------------\n" << std::endl;

	std::string testspecial[] = {
	    " 42", "42 ", " 42 ", 
	    "00042", "0042.00"
	};

	for (size_t i = 0; i < sizeof(testspecial) / sizeof(testspecial[0]); i++)
	{
		std::cout << BLUE << testspecial[i] << NC << std::endl;
		ScalarConverter::convert(testspecial[i]);
		std::cout << std::endl;
	}
}

int main()
{
	std::string input;
	while (true) 
	{
		std::cout << "Enter a value, 'unit' or 'exit': ";
		if (!(std::cin >> input))
			break;
		if (input == "exit" || input == "EXIT" || input == "Exit" || input == "q")
			break;
		else if (input == "unit_test" || input == "unit")
			unit_test();
		else
			ScalarConverter::convert(input);
	}
	return 0;
}

