/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:22:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 12:08:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";

	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;

	*this = copy;
}

WrongCat	&WrongCat::operator=(WrongCat const &copy)
{
	std::cout << "WrongCat assignation operator called" << std::endl;

	WrongCat const *nullcheck = &copy;
	if (this == &copy || nullcheck == NULL)
		return *this;

	this->_type = copy._type;

	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}


void	WrongCat::makeSound( void ) const
{
	std::cout << "Meow! Meow!! MEEEEEOOOOOOOOOWWW!!!!" << std::endl;
}

std::string	WrongCat::getType( void ) const
{
	return _type;
}
