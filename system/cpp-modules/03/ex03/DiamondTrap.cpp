/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:38:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/24 16:56:15 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap " << "Default constructor called" << std::endl;

	this->_name = "default_DT";
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << "Parameterized constructor called" << std::endl;

	this->_name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << "Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap " << "Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &copy)
{
	std::cout << "DiamondTrap " << "Assignment operator called" << std::endl;
	FragTrap::operator=(copy);
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_hitpoints <= 0)
		std::cout << "[Dead DiamondTrap " << this->_name << " cannot express who it is #RIP]" << std::endl;
	else
	{
		std::cout << "[" << this->_name << "] " << "Heyyy I'm " << this->_name;
		std::cout << ", derived from "  << ClapTrap::_name << "!" << std::endl;
	}
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}
