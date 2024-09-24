/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:36:26 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/24 14:44:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap one("♡");
	ClapTrap two("♧");

	std::cout << std::endl;
	
	one.attack("♧");
	one.takeDamage(9);
	one.beRepaired(3);
	one.takeDamage(15);
	one.beRepaired(3);

	std::cout << std::endl;

	two.attack("♡");
	two.takeDamage(0);
	two.beRepaired(3);
	
	std::cout << std::endl;

	ClapTrap test("♢");
	test.attack("♧");
	test.attack("♧");
	test.attack("♧");
	test.attack("♧");
	test.attack("♧");
	test.attack("♧");
	test.attack("♧");
	test.attack("♧");
	test.attack("♧");
	test.beRepaired(0);
	test.attack("♧");
	test.beRepaired(0);
	test.attack("♧");
	
	return 0;
}
