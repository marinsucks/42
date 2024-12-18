/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:14:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/18 17:43:14 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;	
	}

	std::string arg = argv[1];
	for (int i = 2; i < argc; i++)
		arg += " " + std::string(argv[i]);
	
	PmergeMe merge;
	merge.run(arg);

	return 0;
}
