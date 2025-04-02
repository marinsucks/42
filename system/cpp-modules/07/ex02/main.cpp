/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:56:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/29 13:58:37 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void	indextest(Array<T>& foo)
{
	std::cout << "INDEX TEST" << std::endl;
	try
	{
		for (unsigned int i = 0; i < 7; i++)
		{
			foo[i] = i;
			std::cout << "foo[" << i << "] = " << foo[i] << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Content: [" << foo << "]" << std::endl;
	std::cout << "Size:    " << foo.size() << std::endl;
	std::cout << std::endl;
}

template <typename T>
void	test(Array<T>& foo, std::string name)
{
	std::cout << name << std::endl;
	std::cout << "Content: [" << foo << "]" << std::endl;
	std::cout << "Size:    " << foo.size() << std::endl;
	std::cout << std::endl;
}

int main()
{
	Array<int> empty;
	test(empty, "EMPTY");


	Array<int> normal(5);
	test(normal, "NORMAL");

	indextest(normal);
	test(normal, "NORMAL AFTER INDEX TEST");

	Array<int> assign;
	assign = normal;
	test(assign, "ASSIGN (FROM NORMAL)");

	Array<int> copy(normal);
	test(copy, "COPY (FROM NORMAL)");

	Array<int> emptycpy(empty);
	test(emptycpy, "COPY (FROM EMPTY)");

	Array<std::string> str(3);
	test(str, "STRING BEFORE INDEX TEST");
	str[0] = "Hello";
	str[1] = "World";
	str[2] = "!";
	test(str, "STRING AFTER INDEX TEST");

	return (0);
}
