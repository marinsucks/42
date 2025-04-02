/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:53:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/31 12:31:29 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "STL.hpp"
#include "easyfind.hpp"

template <class STL>
void	test(std::string container)
{
	std::cout << container << ":" << std::endl;
	
	STL stl;
	for (int i = 0; i < 10; i++)
		stl.insert(stl.begin(), i);

	std::cout << "Container contains: ";
	for (typename STL::iterator it = stl.begin(); it != stl.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	try
	{
		std::cout << "Looking for 5 in the container: ";
		std::cout << easyfind(stl, 5) << std::endl;

		std::cout << "Looking for 42 in the container: ";
		std::cout << easyfind(stl, 42) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	test<std::vector	<int> >("VECTOR");
	test<std::list		<int> >("LIST");
	test<std::deque		<int> >("DEQUE");
	test<std::set		<int> >("SET");
	test<std::multiset	<int> >("MULTISET");

	return (0);
}
