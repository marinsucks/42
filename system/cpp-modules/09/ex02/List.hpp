/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:44:53 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/20 17:24:57 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AContainer.hpp"
#include <list>

class List : public AContainer< std::list<int> >
{
	private:		
		std::pair<std::list<int>, std::list<int> > divide(std::list<int> &ctr);
		void merge(std::list<int> &left, std::list<int> &right, std::list<int> &ctr);
		void mergeSort(std::list<int> & ctr);

	public:
		List();
		List(const List & copy);
		List & operator=(const List & copy);
		~List();

		double sort();
};
