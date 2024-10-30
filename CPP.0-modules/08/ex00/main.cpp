/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/30 17:58:12 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <map>


void vectorTest(void)
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	std::cout << "Vector contains: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	try
	{
		std::cout << "Looking for 5 in the vector : ";
		std::cout << easyfind(v, 5) << std::endl;

		std::cout << "Looking for 42 in the vector: ";
		std::cout << easyfind(v, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void mapTest(void)
{
	std::map<int, std::string> m;
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";

	std::cout << "Map contains: ";
	for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " : " << it->second << " ";
	std::cout << std::endl;

	try
	{
		std::cout << "Looking for 2 in the map : ";
		std::cout << easyfind(m, 2) << std::endl;

		std::cout << "Looking for 42 in the map: ";
		std::cout << easyfind(m, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{

	vectorTest();

	std::cout << std::endl;

	mapTest();

	return (0);
}
