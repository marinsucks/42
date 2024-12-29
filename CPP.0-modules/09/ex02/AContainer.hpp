/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:44:53 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/29 12:21:58 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <algorithm>

#include "colors.hpp"

template <typename Container>
class AContainer
{
	protected:
		Container _ctr;
		double	_start;
		double	_elapsed;

		virtual void monitorStart();
		virtual void monitorEnd();

		virtual void mergeSort(Container & ctr) = 0;
	
	public:
		AContainer();
		AContainer(const AContainer & copy);
		AContainer & operator=(const AContainer & copy);
		virtual ~AContainer();
	
		virtual void push_back(int value);
		virtual bool contains(int value) const;
		virtual size_t size() const;
		virtual void print() const;
		virtual void print(Container &ctr) const;
		virtual bool isSorted() const;

		virtual double sort() = 0;
};

#include "AContainer.tpp"
