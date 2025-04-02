/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:41:58 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/23 14:07:31 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

std::string boolToString(bool value)
{
	return (value ? "true" : "false");
}

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "\n";
	
	Fixed c( 0 );
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

	std::cout << "TRUE: " << std::endl;	
    std::cout << "a < b:  " << boolToString(a < b) << std::endl;
    std::cout << "a <= b: " << boolToString(a <= b) << std::endl;
    std::cout << "a != b: " << boolToString(a != b) << std::endl;
    std::cout << "a > c:  " << boolToString(a > c) << std::endl;
    std::cout << "a >= c: " << boolToString(a >= c) << std::endl;
    std::cout << "a != c: " << boolToString(a != c) << std::endl;
	
	std::cout << "FALSE: " << std::endl;	
    std::cout << "a > b:  " << boolToString(a > b) << std::endl;
    std::cout << "a >= b: " << boolToString(a >= b) << std::endl;
    std::cout << "a == b: " << boolToString(a == b) << std::endl;
    std::cout << "a < c:  " << boolToString(a < c) << std::endl;
    std::cout << "a <= c: " << boolToString(a <= c) << std::endl;
    std::cout << "a == c: " << boolToString(a == c) << std::endl;

	std::cout << "b * 0 >= c: " << boolToString(((Fixed)b * (Fixed)0) >= c) << std::endl;


	Fixed const d( 1 );
	Fixed const e( -1 );
	Fixed f( 0 );
	Fixed g( 0 );

	std::cout << "MIN a/b: " << Fixed::min(a, b) << std::endl;
	std::cout << "MAX a/b:" << Fixed::max(a, b) << std::endl;
	std::cout << "MIN c/d: " << Fixed::min(c, d) << std::endl;
	std::cout << "MAX c/d: " << Fixed::max(c, d) << std::endl;
	std::cout << "MIN e/f: " << Fixed::min(e, f) << std::endl;
	std::cout << "MAX e/f: " << Fixed::max(e, f) << std::endl;
	std::cout << "MIN g/f: " << Fixed::min(g, f) << std::endl;
	std::cout << "MAX g/f: " << Fixed::max(g, f) << std::endl;

	return 0;
}
