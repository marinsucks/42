/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:43:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/23 14:04:20 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _val(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int arg): _val(arg * (1 << this->_fractionalBits))
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float arg): _val(roundf(arg * (1 << this->_fractionalBits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_val = other._val;
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
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


bool	Fixed::operator>( const Fixed &that )
{
	return (this->_val > that._val);
}

bool	Fixed::operator>=( const Fixed &that )
{
	return (this->_val >= that._val);
}

bool	Fixed::operator<( const Fixed &that )
{
	return (this->_val < that._val);
}

bool	Fixed::operator<=( const Fixed &that )
{
	return (this->_val <= that._val);
}

bool	Fixed::operator==( const Fixed &that )
{
	return (this->_val == that._val);
}

bool	Fixed::operator!=( const Fixed &that )
{
	return (this->_val != that._val);
}


Fixed	Fixed::operator+( const Fixed &that )
{
	Fixed result(this->toFloat() + that.toFloat());
	return (result);
}

Fixed	Fixed::operator-( const Fixed &that )
{
	Fixed result(this->toFloat() - that.toFloat());
	return (result);
}

Fixed	Fixed::operator*( const Fixed &that )
{
	Fixed result(this->toFloat() * that.toFloat());
	return (result);
}

Fixed	Fixed::operator/( const Fixed &that )
{
	Fixed result(this->toFloat() / that.toFloat());
	return (result);
}


Fixed	Fixed::operator++( void )
{
	this->_val++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed temp(*this);

	this->_val++;
	return temp;
}

Fixed	Fixed::operator--( void )
{
	this->_val--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed temp(*this);

	this->_val--;
	return temp;
}


Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	return (a < b ? a : b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	return (a > b ? a : b);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b )
{
	Fixed x = a;
	Fixed y = b;
	return (x < y ? a : b);
}

Fixed const	&Fixed::max( Fixed const &a, Fixed const &b )
{
	Fixed x = a;
	Fixed y = b;
	return (x > y ? a : b);
}
