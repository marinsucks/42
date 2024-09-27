/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/27 18:24:38 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	//std::cout << "Character - Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	//std::cout << "Character - Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = other._inventory[i];
}

Character& Character::operator=(const Character& other)
{
	//std::cout << "Character - Assignment operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	//std::cout << "Character - Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i < 4)
		this->_inventory[i++] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 && idx >= 4)
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, Character& target)
{
	if (idx < 0 && idx >= 4)
		return ;
	this->_inventory[idx]->use(target);
}
