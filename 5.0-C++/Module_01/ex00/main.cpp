/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:17:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/08 12:57:44 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	Zombie* zombie = newZombie("Heapie");
	zombie->announce();
	delete zombie;
	randomChump("Stackie");
	return 0;
}
