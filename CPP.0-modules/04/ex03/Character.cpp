/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:21 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/14 17:07:24 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

// CONSTRUCTORS | DESTRUCTOR

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name)
{
	if (name.empty())
		this->_name = "default";
	else
		this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& copy) //: _inventory({NULL, NULL, NULL, NULL})
{
	if (this == &copy)
		return ;
	*this = copy;
}

Character& Character::operator=(const Character& copy)
{
	if (this == &copy)
		return *this;

	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
		{
			this->_inventory[i] = copy._inventory[i]->clone();
			if (!this->_materias.contains(this->_inventory[i]))
				this->_materias.push(this->_inventory[i]);
		}
		else
			this->_inventory[i] = NULL;
	}
	this->_name = copy._name;
	
	return *this;
}

Character::~Character() 
{
	this->_materias.clear();
}


// PUBLIC MEMBER FUNCTIONS

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i >= 4)
		return ;

	this->_inventory[i++] = m;
	if (!this->_materias.contains(m))
		this->_materias.push(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
