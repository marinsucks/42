/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:18:00 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/09 11:38:30 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

void	Zombie::announce(void)
{
	std::cout << this->_name << FS << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::string deathMsg[] = {
		"flabbergasted",
		"put down",
		"obliterated",
		"exterminated",
		"demolished",
		"annihilated",
		"eliminated",
		"erased",
		"terminated",
		"extinguished",
		"eradicated",
		"vanquished",
		"destroyed",
		"smashed",
		"crushed",
		"shattered",
		"sent to hell",
	};
	
	srand(time(0) + clock());
	int i = rand() % (sizeof(deathMsg) / sizeof(deathMsg[0]));
	
	std::cout << this->_name << " has been " << deathMsg[i] << "." << std::endl;
}
