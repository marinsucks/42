/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:19:06 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 14:03:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";

	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	this->_type = copy._type;

	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &copy)
{
	this->_type = copy._type;

	std::cout << "Dog assignation operator called" << std::endl;

	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}


void	Dog::makeSound( void ) const
{
	std::cout << "Bark! Bark!! BAAAAAAAAAAAAARRKK!!!!" << std::endl;
}

std::string	Dog::getType( void ) const
{
	return _type;
}
