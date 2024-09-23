/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:44:07 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/23 14:02:44 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_val;
		static const int	_fractionalBits;
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed	&operator=(const Fixed &other);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool	operator>( const Fixed &that );
		bool	operator>=( const Fixed &that );
		bool	operator<( const Fixed &that );
		bool	operator<=( const Fixed &that );
		bool	operator==( const Fixed &that );
		bool	operator!=( const Fixed &that );

		Fixed	operator+( const Fixed &that );
		Fixed	operator-( const Fixed &that );
		Fixed	operator*( const Fixed &that );
		Fixed	operator/( const Fixed &that );

		Fixed	operator++( void );
		Fixed	operator++( int );
		Fixed	operator--( void );
		Fixed	operator--( int );

		static Fixed const	&min( Fixed const &a, Fixed const &b );
		static Fixed const	&max( Fixed const &a, Fixed const &b );
		static Fixed	&min( Fixed &a, Fixed &b );
		static Fixed	&max( Fixed &a, Fixed &b );
};

std::ostream	&operator<<(std::ostream& outstr, Fixed const &num);

#endif