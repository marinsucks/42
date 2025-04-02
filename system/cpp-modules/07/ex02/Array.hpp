/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:44:51 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/29 13:26:49 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		
		T& operator[](unsigned int n);
		const T& operator[](unsigned int n) const;

		class OutOfBounds : public std::exception
		{
			public:
				const char *what() const throw();
		};

		unsigned int size(void) const;
};

#include "Array.tpp"

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& foo);
