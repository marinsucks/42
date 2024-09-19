/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:44:07 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/19 11:03:41 by mbecker          ###   ########.fr       */
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
};

std::ostream	&operator<<(std::ostream& outstr, Fixed const &num);

#endif