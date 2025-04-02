/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AContainer.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:03:34 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/20 17:39:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AContainer.hpp"

template <typename Container>
AContainer<Container>::AContainer() 
	: _ctr(), _start(0), _elapsed(0)
{}

template <typename Container>
AContainer<Container>::AContainer(const AContainer & copy) 
	: _ctr(copy._ctr), _start(copy._start), _elapsed(copy._elapsed)
{}

template <typename Container>
AContainer<Container> & AContainer<Container>::operator=(const AContainer & copy)
{
	if (this != &copy)
	{
		_ctr = copy._ctr;
		_start = copy._start ;
		_elapsed = copy._elapsed ;
	}

	return *this;
}

template <typename Container>
AContainer<Container>::~AContainer() 
{}


/******* PRIVATE METHODS *******/

template <typename Container>
void AContainer<Container>::monitorStart()
{
	_start = std::clock();
}

template <typename Container>
void AContainer<Container>::monitorEnd()
{
	std::clock_t _end = std::clock();
	_elapsed = (static_cast<double>(_end - _start) / CLOCKS_PER_SEC) * 1000;
}



/******* PUBLIC METHODS *******/ 

template <typename Container>
void AContainer<Container>::push_back(int value)
{
	_ctr.push_back(value);
}

template <typename Container>
bool AContainer<Container>::contains(int value) const
{
	return std::find(_ctr.begin(), _ctr.end(), value) != _ctr.end();
}

template <typename Container>
size_t AContainer<Container>::size() const
{
	return _ctr.size();
}

template <typename Container>
void AContainer<Container>::print() const
{
	for (typename Container::const_iterator it = _ctr.begin(); it != _ctr.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename Container>
bool AContainer<Container>::isSorted() const
{
	typename Container::const_iterator it = _ctr.begin();
	typename Container::const_iterator ite = _ctr.end();
	if (it == ite)
		return true;

	typename Container::const_iterator it_next = it;
	++it_next;
	while (it_next != ite)
	{
		if (*it > *it_next)
			return false;
		++it;
		++it_next;
	}
	return true;
}

template <typename Container>
void AContainer<Container>::print(Container &ctr) const
{
	for (typename Container::const_iterator it = ctr.begin(); it != ctr.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}



