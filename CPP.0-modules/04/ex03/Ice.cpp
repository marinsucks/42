/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/27 13:07:17 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	//std::cout << "Ice - Default constructor called" << std::endl;

	_type = "ice";
}

Ice::Ice(const Ice& other)
{
	//std::cout << "Ice - Copy constructor called" << std::endl;

	_type = "ice";
}

Ice& Ice::operator=(const Ice& other)
{
	//std::cout << "Ice - Assignment operator called" << std::endl;

	this->_type = other._type;
	return *this;
}

Ice::~Ice()
{
	//std::cout << "Ice - Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}