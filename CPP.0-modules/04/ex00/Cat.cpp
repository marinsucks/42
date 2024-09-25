/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:22:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 14:02:45 by mbecker          ###   ########.fr       */
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
	this->_type = copy._type;

	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &copy)
{
	this->_type = copy._type;

	std::cout << "Cat assignation operator called" << std::endl;

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
