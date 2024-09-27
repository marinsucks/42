/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:21:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/26 15:07:09 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	//std::cout << "AMateria - Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	//std::cout << "AMateria - Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	//std::cout << "AMateria - Assignment operator called" << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria - Destructor called" << std::endl;
}
