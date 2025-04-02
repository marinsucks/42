/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:33:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/24 16:12:29 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap " << "Default constructor called" << std::endl;

	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guarding_gate = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << "Parameterized constructor called" << std::endl;

	this->_name = name;
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	this->_guarding_gate = false;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << "Copy constructor called" << std::endl;

	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap " << "Assignment operator called" << std::endl;
	
	_name = other._name;
	_hitpoints = other._hitpoints;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	_guarding_gate = other._guarding_gate;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << "Destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (_guarding_gate)
	{
		std::cout << "ScavTrap " << _name << " is already guarding the gate." << std::endl;
		return ;
	}
	_guarding_gate = true;
	std::cout << "ScavTrap " << _name << " started guarding the gate!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hitpoints > 0)
	{
		this->_energy_points -= 1;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else if (this->_energy_points <= 0)
		std::cout << "ScavTrap " << _name << " cannot attack: is out of energy points!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " cannot attack: it is dead!" << std::endl;
}
