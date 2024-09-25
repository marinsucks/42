/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:19:06 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 16:47:58 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"



Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	
	_type = "Dog";
	_brain = new Brain();
	_brain->appendIdeas("Dog ");
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;

	this->_type = copy._type;
}

Dog	&Dog::operator=(Dog const &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;

	this->_type = copy._type;
	return *this;
}

Dog::~Dog()
{
	delete _brain; 

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

Brain	*Dog::getBrain( void ) const
{
	return _brain;
}
