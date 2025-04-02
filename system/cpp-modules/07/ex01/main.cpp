/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:27:05 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/28 16:36:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "iter.hpp"

void	upper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void	numberify(char &c)
{
	if (c == 'E')
		c = '3';
	else if (c == 'A')
		c = '4';
	else if (c == 'S')
		c = '5';
	else if (c == 'T')
		c = '7';
	else if (c == 'O')
		c = '0';
}

int main()
{
	char hey[] = "Some normal text, why would it change ??";
	std::cout << "Original string:\t" << hey << std::endl;
	
	iter(hey, static_cast<std::string>(hey).length(), upper);
	std::cout << "After upper:\t\t" << hey << std::endl;

	iter(hey, static_cast<std::string>(hey).length(), numberify);
	std::cout << "After numberify:\t" << hey << std::endl;
	return 0;
}
