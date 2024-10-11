/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:21:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/08 17:49:09 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria& other) { *this = other; }

AMateria& AMateria::operator=(const AMateria& other)
{
	AMateria const *nullcheck = &other;
	if (this == &other || nullcheck == NULL)
		return *this;
	
	this->_type = other._type;

	return *this;
}

AMateria::~AMateria() {}

void AMateria::use(ICharacter& target) { (void)target; }
