/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:48:05 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/29 13:50:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"	

List::List()
{}

List::List(const List & copy)
{
	*this = copy;
}

List & List::operator=(const List & copy)
{
	if (this != &copy)
	{
		_ctr = copy._ctr;
	}
	return *this;
}
List::~List()
{}

/******* PRIVATE METHODS *******/

std::pair<std::list<int>, std::list<int> > List::divide(std::list<int> &ctr)
{
	std::list<int>::iterator middle = ctr.begin();
	std::advance(middle, ctr.size() / 2);

	std::list<int> left(ctr.begin(), middle);
	std::list<int> right(middle, ctr.end());

	return (std::make_pair(left, right));
}


void List::merge(std::list<int> &left, std::list<int> &right, std::list<int> &ctr)
{
	std::list<int>::iterator it_left = left.begin();
	std::list<int>::iterator it_right = right.begin();
	std::list<int>::iterator it_ctr = ctr.begin();

	while (it_left != left.end() && it_right != right.end())
	{
		if (*it_left < *it_right)
			*(it_ctr++) = *(it_left++);
		else
			*(it_ctr++) = *(it_right++);
	}

	while (it_left != left.end())
		*(it_ctr++) = *(it_left++);

	while (it_right != right.end())
		*(it_ctr++) = *(it_right++);
}

void List::mergeSort(std::list<int> &ctr)
{
	//std::cout << "Sorting list of size " << ctr.size() << std::endl;
	if (ctr.size() <= 1)
		return;

	std::pair<std::list<int>, std::list<int> > divided = divide(ctr);
	std::list<int> left = divided.first;
	std::list<int> right = divided.second;

	mergeSort(left);
	mergeSort(right);
	merge(left, right, ctr);
}

/******* PUBLIC METHODS *******/

double List::sort()
{
	monitorStart();

	mergeSort(_ctr);

	monitorEnd();

	return _elapsed;
}
