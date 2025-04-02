/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:13:59 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/14 13:12:55 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	if (this == &copy)
		return ;

	this->_type = copy._type;
}

Animal	&Animal::operator=(Animal const &copy)
{
	if (this == &copy)
		return *this;

	this->_type = copy._type;

	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return _type;
}
