/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:43:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/19 11:25:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

static	float power(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp = -exp;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

Fixed::Fixed(): _val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value): _val(value * power(2, this->_fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value): _val(value * power(2, this->_fractionalBits))
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
	std::cout << "toFloat: ";
	std::cout << "this->val = " << this->_val << "; ";
	std::cout << "power = " << power(2, -this->_fractionalBits);
	std::cout << std::endl << std::endl;

	return (this->_val * power(2, -this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	std::cout << "toInt: ";
	std::cout << "this->val = " << this->_val << "; ";
	std::cout << "power = " << power(2, -this->_fractionalBits);
	std::cout << std::endl << std::endl;

	return (this->_val * power(2, -this->_fractionalBits));
}

std::ostream	&operator<<( std::ostream& outstr, Fixed const &num)
{
	return (outstr << num.toFloat());
}
