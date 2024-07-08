/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:17:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/08 12:45:11 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//It creates a zombie, names it, and returns it.
void randomChump( std::string name )
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}
