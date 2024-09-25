/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:18:54 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 16:36:53 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_brain;
public:
	Dog();
	Dog(Dog const &copy);
	Dog &operator=(Dog const &copy);
	virtual ~Dog();

	void		makeSound( void ) const;
	std::string	getType( void ) const;
	Brain		*getBrain( void ) const;
};
