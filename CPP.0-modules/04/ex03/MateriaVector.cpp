/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaVector.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:10:09 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/10 16:26:23 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaVector.hpp"

MateriaVector::MateriaVector(): _vector(NULL), _size(0), _capacity(0)
{
}

MateriaVector::MateriaVector(const MateriaVector& copy)
{
	MateriaVector const *nullcheck = &copy;
	if (nullcheck == NULL)
		*this = MateriaVector();
	else if (this != &copy)
		*this = copy;
}

MateriaVector& MateriaVector::operator=(const MateriaVector& copy)
{
	MateriaVector const *nullcheck = &copy;
	if (this == &copy || nullcheck == NULL)
		return *this;
	
	return *this;
}

MateriaVector::~MateriaVector() 
{
	this->clear();
}

void	MateriaVector::push(AMateria *ptr)
{
	if (this->_size == this->_capacity)
	{
		if (this->_capacity == 0)
			this->_capacity = 1;
		else
			this->_capacity *= 2; // avoid reallocating too often
		AMateria **tmp = new AMateria*[this->_capacity];
		for (int i = 0; i < this->_size; i++)
			tmp[i] = this->_vector[i];
		delete[] this->_vector;
		this->_vector = tmp;
	}
	this->_vector[this->_size] = ptr;
	this->_size++;
}

void	MateriaVector::clear(void)
{
	if (this->_vector == NULL)
		return;
	for (int i = 0; i < this->_size; i++)
		delete this->_vector[i];
	delete[] this->_vector;
	this->_vector = NULL;
	this->_size = 0;
	this->_capacity = 0;
}

bool	MateriaVector::contains(AMateria *ptr) const
{
	for (int i = 0; i < this->_size; i++)
		if (this->_vector[i] == ptr)
			return true;
	return false;
}
