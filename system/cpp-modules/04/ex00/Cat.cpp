/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:22:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/14 13:14:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";

	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;

	this->_type = copy._type;
}

Cat	&Cat::operator=(Cat const &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;

	if (this == &copy)
		return *this;

	this->_type = copy._type;

	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}


void	Cat::makeSound( void ) const
{
	std::cout << "Meow! Meow!! MEEEEEOOOOOOOOOWWW!!!!" << std::endl;
}

std::string	Cat::getType( void ) const
{
	return _type;
}
