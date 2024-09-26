/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:14:04 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 17:51:06 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal& copy);
	AAnimal& operator=(const AAnimal& copy);
	virtual ~AAnimal();

	virtual void 		makeSound( void ) const = 0;
	std::string			getType( void ) const;

	virtual Brain		*getBrain( void ) const;
};
