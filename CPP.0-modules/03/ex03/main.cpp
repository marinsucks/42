/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:36:26 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/24 15:00:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap heart("♡");
	ClapTrap club("♧");
	
	std::cout << std::endl;

	heart.attack("♧");
	club.takeDamage(0);
	club.attack("♡");
	heart.takeDamage(0);
	club.beRepaired(3);

	std::cout << std::endl;

	ScavTrap spike("♤");
	ScavTrap diamond("♢");

	std::cout << std::endl;

	spike.attack("♢");
	diamond.takeDamage(20);
	diamond.attack("♤");
	spike.takeDamage(20);

	spike.guardGate();
	diamond.guardGate();
	spike.guardGate();


	std::cout << std::endl;

	FragTrap yo("yo");
	FragTrap lo("lo");

	std::cout << std::endl;

	yo.attack("lo");
	lo.takeDamage(30);
	lo.attack("yo");
	yo.takeDamage(30);

	yo.highFivesGuys();
	lo.highFivesGuys();
	yo.highFivesGuys();

	std::cout << std::endl;

	FragTrap test("test");

	std::cout << std::endl;

	test.attack("target");

	// Test the energy points
	for (int i = 0; i < 100; i++)
	{
		test.attack("target");
		std::cout << "\033[1A\033[2K"; // Erase last output line on std::cout
	}
	test.attack("target");

	
	std::cout << std::endl;

	return 0;
}
