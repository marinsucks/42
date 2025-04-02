/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:13:59 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 16:45:17 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;

	AAnimal const *nullcheck = &copy;
	if (nullcheck == NULL)
		return ;
	else if (this != &copy)
		*this = copy;
}

AAnimal	&AAnimal::operator=(AAnimal const &copy)
{
	std::cout << "AAnimal assignation operator called" << std::endl;

	AAnimal const *nullcheck = &copy;
	if (this == &copy || nullcheck == NULL)
		return *this;

	this->_type = copy._type;

	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void	AAnimal::makeSound( void ) const
{
	std::cout << "AAnimal sound" << std::endl;
}

std::string	AAnimal::getType( void ) const
{
	return _type;
}

Brain	*AAnimal::getBrain( void ) const
{
	return NULL;
}
