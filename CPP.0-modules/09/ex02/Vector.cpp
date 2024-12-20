/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:48:05 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/20 17:57:11 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"	

/***** CONSTRUCTORS / DESTRUCTORS *****/
Vector::Vector()
{}

Vector::Vector(const Vector & copy)
{
	*this = copy;
}

Vector & Vector::operator=(const Vector & copy)
{
	if (this != &copy)
	{
		_ctr = copy._ctr;
	}
	return *this;
}

Vector::~Vector()
{}


/***** PRIVATE METHODS *****/

std::pair<std::vector<int>, std::vector<int> > Vector::divide(std::vector<int> &ctr)
{
	std::vector<int> left(ctr.begin(), ctr.begin() + (ctr.size() / 2));
	std::vector<int> right(ctr.begin() + (ctr.size() / 2), ctr.end());
	
	return (std::make_pair(left, right));
}

void Vector::merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &ctr)
{
	int i = 0;

	for (std::vector<int>::iterator lv = left.begin(); lv < left.end(); lv++)
	{
		for (std::vector<int>::iterator rv = right.begin(); rv < right.end(); rv++)
		{
			if (*lv < *rv)
				break;
			ctr[i++] = *rv;
			right.erase(rv); // erase current and returns the next iterator
		}
		ctr[i++] = *lv;
	}

	for (std::vector<int>::iterator lv = right.begin(); lv < right.end(); lv++)
	{
		std::vector<int>::iterator rv = lv + 1;
		if (rv == right.end())
		{
			ctr[i++] = *lv;
			break;
		}
		if (*lv < *rv)
			ctr[i++] = *lv;
		else
			ctr[i++] = *rv;
	}
}

void Vector::mergeSort(std::vector<int> &ctr)
{
	//std::cout << "Sorting vector of size " << ctr.size() << std::endl;
	if (ctr.size() <= 1)
		return;

	std::pair<std::vector<int>, std::vector<int> > divided = divide(ctr);
	std::vector<int> left = divided.first;
	std::vector<int> right = divided.second;

	mergeSort(left);
	mergeSort(right);
	merge(left, right, ctr);
}


/***** PUBLIC METHODS *****/

double Vector::sort()
{
	monitorStart();

	mergeSort(_ctr);

	monitorEnd();

	return _elapsed;
}
