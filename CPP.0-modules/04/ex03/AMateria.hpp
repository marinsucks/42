/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:21:26 by mbecker           #+#    #+#             */
/*   Updated: 2024/09/30 15:17:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const &copy);
		AMateria &operator=(AMateria const &copy);
		virtual ~AMateria();

		virtual std::string const & getType() const = 0;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
