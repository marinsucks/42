/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:25:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/22 17:54:32 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{

	std::string input;
	while (true) 
	{
		std::cout << "Enter a value, or exit: ";
		if (!(std::cin >> input))
			break;
		if (input == "exit" || input == "EXIT" || input == "Exit" || input == "q")
			break;
		ScalarConverter::convert(input);
	}
	return 0;
}
