/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:24:20 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/31 16:42:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	subj()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	longest()
{
	Span sp = Span(15000);

	std::vector<int> values;
	for (int i = 0; i < 15000; i++)
		values.push_back(i);
	sp.addNumber(values.begin(), values.end());
	
	std::cout << sp.longestSpan() << std::endl;
}


void	iterator()
{
    Span span(10);

	try 
	{
		for (int i = 0; i < 20; i += 5)
		{
        	int arr[] = {i + 1, i + 2, i + 3, i + 4, i +5};
			std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

			span.addNumber(vec.begin(), vec.end());

			std::cout << span << std::endl;
		}
    }

	catch (const std::exception& e) 
	{
        std::cout << e.what() << std::endl;
    }
}

int main()
{
	subj();
	std::cout << std::endl;

	longest();
	std::cout << std::endl;

	iterator();

	return 0;
}
