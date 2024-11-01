/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:51:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/11/01 16:09:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename CTR>
MutantStack<T, CTR>::MutantStack() {}

template <typename T, typename CTR>
MutantStack<T, CTR>::MutantStack(CTR ctr) : std::stack<T, CTR>(ctr) {}

template <typename T, typename CTR>
MutantStack<T, CTR>::MutantStack(const MutantStack& other) 
{
	if (this != &other)
		*this = other;
}

template <typename T, typename CTR>
MutantStack<T, CTR>&	MutantStack<T, CTR>::operator=(const MutantStack& other) 
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template <typename T, typename CTR>
MutantStack<T, CTR>::~MutantStack() {}

template <typename T, typename CTR>
typename MutantStack<T, CTR>::iterator MutantStack<T, CTR>::begin(void)
{
	return (this->c.begin());
}

template <typename T, typename CTR>
typename MutantStack<T, CTR>::iterator MutantStack<T, CTR>::end(void)
{
	return (this->c.end());
}

template <typename T>
std::ostream& operator<<(std::ostream& os, MutantStack<T>&  ex)
{
	for (std::size_t i = 0; i < ex.size(); i++)
		os << *(ex.begin() + i) << " ";
	return os;
}
