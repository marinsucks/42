/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:33:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/24 13:43:32 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap " << "Default constructor called" << std::endl;
	_hitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << "Parameterized constructor called" << std::endl;

	_name = name;
	_hitpoints = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap " << "Copy constructor called" << std::endl;

	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << "Assignment operator called" << std::endl;

	_name = other._name;
	_hitpoints = other._hitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;

	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy points!" << std::endl;
		return;
	}
	this->_energy_points--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	this->_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of energy points!" << std::endl;
		return;
	}
	if (this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
		return;
	}
	if (this->_hitpoints == 10)
	{
		std::cout << "ClapTrap " << _name << " is already at full health." << std::endl;
		return;
	}
	this->_hitpoints += amount;
	if (this->_hitpoints > 10)
		this->_hitpoints = 10;
	this->_energy_points--;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
}
