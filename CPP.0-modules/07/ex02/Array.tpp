/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:58:20 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/29 13:50:21 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->_array = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_array[i] = T();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array& copy)
{
	if (this == &copy)
		return ;

	this->_array = new T[copy._size];
	for (unsigned int i = 0; i < copy._size; i++)
		this->_array[i] = copy._array[i];
	this->_size = copy._size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this == &copy)
		return (*this);

	if (this->_array)
		delete[] this->_array;
	this->_array = new T[copy._size];
	for (unsigned int i = 0; i < copy._size; i++)
		this->_array[i] = copy._array[i];
	this->_size = copy._size;
	
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= this->_size)
		throw Array::OutOfBounds();
	return (_array[n]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (n >= this->_size)
		throw Array::OutOfBounds();
	return (_array[n]);
}

template <typename T>
const char * Array<T>::OutOfBounds::what() const throw()
{
	return ("array index out of bounds");
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
std::ostream& operator<<(std::ostream& ostream, const Array<T>& array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		ostream << " " << array[i];
		if (i + 1 == array.size())
			ostream << " ";
	}

	return (ostream);
}
