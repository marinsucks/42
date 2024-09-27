/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/27 13:45:34 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

ICharacter::ICharacter()
{
	//std::cout << "ICharacter - Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

ICharacter::ICharacter(const ICharacter& other)
{
	//std::cout << "ICharacter - Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i];
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
	//std::cout << "ICharacter - Assignment operator called" << std::endl;
	return *this;
}

ICharacter::~ICharacter()
{
	//std::cout << "ICharacter - Destructor called" << std::endl;
}

std::string const & getName()
{

}

void ICharacter::equip(AMateria* m)
{
	int i = this->_inventory.size();
	if (i < 4)
		this->_inventory[i++] = m;
	
}

void ICharacter::unequip(int idx)
{

}

void ICharacter::use(int idx, ICharacter& target)
{

}

