/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:21:09 by mbecker           #+#    #+#             */
/*   Updated: 2024/07/08 17:38:08 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const& Weapon::getType() const
{
	return (this->_type);
};

void Weapon::setType(std::string type)
{
	this->_type = type;
};
