/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:36:26 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/24 14:24:12 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	
	return 0;
}
