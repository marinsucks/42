/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:22:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/02 11:39:00 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;

	_type = "Cat";
	_brain = new Brain();
	_brain->appendIdeas("Cat ");
}

Cat::Cat(Cat const &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;

	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Cat	&Cat::operator=(Cat const &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;

	if (this != &copy)
	{
		this->_type = copy._type;
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;

	std::cout << "Cat destructor called" << std::endl; //make deep copy 
}


void	Cat::makeSound( void ) const
{
	std::cout << "Meow! Meow!! MEEEEEOOOOOOOOOWWW!!!!" << std::endl;
}

std::string	Cat::getType( void ) const
{
	return _type;
}

Brain	*Cat::getBrain( void ) const
{
	return _brain;
}
