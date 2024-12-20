/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:44:53 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/20 16:40:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AContainer.hpp"
#include <vector>

class Vector : public AContainer< std::vector<int> >
{
	private:		
		std::pair<std::vector<int>, std::vector<int> > divide(std::vector<int> &ctr);
		void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &ctr);
		void mergeSort(std::vector<int> & ctr);

	public:
		Vector();
		Vector(const Vector & copy);
		Vector & operator=(const Vector & copy);
		~Vector();

		double sort();
};
