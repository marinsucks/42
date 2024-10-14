/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:16:43 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/14 13:17:39 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;

	*this = copy;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;

	if (this == &copy)
		return *this;

	this->_type = copy._type;

	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Some sound from Wrong animal" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return _type;
}
