/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:17:53 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/08 12:45:08 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Creates a zombie, names it and returns it.
Zombie* newZombie( std::string name )
{
	Zombie* zombie = new Zombie(name);
	return zombie;
}
