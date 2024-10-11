/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:06:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/10 16:27:26 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AMateria.hpp"

class MateriaVector
{
	private:
		AMateria	**_vector;
		int			_size;
		int			_capacity;
	public:
		MateriaVector();
		MateriaVector(const MateriaVector& other);
		MateriaVector& operator=(const MateriaVector& other);
		~MateriaVector();

		void push(AMateria *ptr);
		void clear(void);
		bool contains(AMateria *ptr) const;
};

