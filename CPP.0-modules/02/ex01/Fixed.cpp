/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:43:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/23 12:36:04 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int arg): _val(arg * (1 << this->_fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float arg): _val(roundf(arg * (1 << this->_fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_val = other._val;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_val / (float)(1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return ((int)(this->_val >> this->_fractionalBits));
}

std::ostream	&operator<<( std::ostream& outstr, Fixed const &num)
{
	return (outstr << num.toFloat());
}
