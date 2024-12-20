/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:48:05 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/20 17:59:36 by mbecker          ###   ########.fr       */
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
	//std::cout << "Merging lists of size " << left.size() << " and " << right.size() << std::endl;
	ctr.clear();
	std::list<int>::iterator lv = left.begin();
	std::list<int>::iterator rv = right.begin();

	while (lv != left.end() && rv != right.end())
	{
		if (*lv <= *rv)
			ctr.push_back(*(lv++));
		else
			ctr.push_back(*(rv++));
	}

	
	lv = lv == left.end() ? rv : lv;
		
	while (lv != right.end() && rv != left.end())
	{
		rv = lv;
		++rv;
		if (*lv < *rv)
			ctr.push_back(*(lv));
		else
			ctr.push_back(*(rv));
		++lv;
	}

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
