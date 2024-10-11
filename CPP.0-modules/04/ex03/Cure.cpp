/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:22:45 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/10 14:40:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";	
}

Cure::Cure(Cure const &copy)
{
	Cure const *nullcheck = &copy;
	if (nullcheck == NULL)
		*this = Cure();
	else if (this != &copy)
		*this = copy;
}

Cure& Cure::operator=(const Cure& other) 
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Cure::~Cure() {}

std::string const & Cure::getType() const
{
	return _type;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
