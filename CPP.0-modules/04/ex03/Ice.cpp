/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/30 15:50:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// CONSTRUCTORS | DESTRUCTOR

Ice::Ice()
{
	_type = "cure";	
}

Ice::Ice(const Ice& other) { *this = other; }

Ice& Ice::operator=(const Ice& other) 
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Ice::~Ice() {}


// PUBLIC MEMBER FUNCTIONS

std::string const & Ice::getType() const
{
	return _type;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
