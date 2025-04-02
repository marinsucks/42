/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:23:00 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/26 14:18:31 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*_brain;
public:
	Cat();
	Cat(Cat const &copy);
	Cat &operator=(Cat const &copy);
	virtual ~Cat();

	void	makeSound( void ) const;
	std::string	getType( void ) const;
	Brain		*getBrain( void ) const;
};
