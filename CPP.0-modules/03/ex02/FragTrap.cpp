/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:33:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/24 14:42:55 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap " << "Default constructor called" << std::endl;

	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << "Parameterized constructor called" << std::endl;

	this->_name = name;
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "FragTrap " << "Copy constructor called" << std::endl;

	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap " << "Assignment operator called" << std::endl;

	_name = other._name;
	_hitpoints = other._hitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << "Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	bool accepted = true;
	if (accepted)
		std::cout << "FragTrap " << _name << " passed the vibe check." << std::endl;
}
