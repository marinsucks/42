/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:19:06 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/08 17:15:55 by mbecker          ###   ########.fr       */
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
	std::cout << "Dog copy constructor called" << std::endl;

	*this = copy;
}

Dog	&Dog::operator=(Dog const &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;

	Dog const *nullcheck = &copy;
	if (this == &copy || nullcheck == NULL)
		return *this;

	this->_type = copy._type;

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
