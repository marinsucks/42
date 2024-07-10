/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:17:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/09 16:13:57 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " [debug/info/warning/error]" << std::endl;
		return 1;
	}
	for (int i = 1; argv[i]; i++)
		harl.complain(argv[i]);
	return 0;
}