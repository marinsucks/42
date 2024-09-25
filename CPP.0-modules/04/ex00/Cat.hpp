/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:23:00 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/25 12:05:04 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat const &copy);
	Cat &operator=(Cat const &copy);
	virtual ~Cat();

	void	makeSound( void ) const;
	std::string	getType( void ) const;
};
