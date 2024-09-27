/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:45 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/27 13:30:44 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	//std::cout << "Cure - Default constructor called" << std::endl;

	_type = "cure";	
}

Cure::Cure(const Cure& other)
{
	//std::cout << "Cure - Copy constructor called" << std::endl;

	_type = "cure";
}

Cure& Cure::operator=(const Cure& other)
{
	//std::cout << "Cure - Assignment operator called" << std::endl;

	this->_type = other._type;
	return *this;
}

Cure::~Cure()
{
	//std::cout << "Cure - Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
