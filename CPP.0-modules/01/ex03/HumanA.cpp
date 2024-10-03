/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:32:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/03 11:11:44 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

void HumanA::attack()
{
	if (this->_weapon.getType() == "")
		std::cout << this->_name << " has no weapon to attack with" << std::endl;
	else
		std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
