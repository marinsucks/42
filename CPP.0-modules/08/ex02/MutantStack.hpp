/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:23:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/11/01 16:06:58 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "STL.hpp"
#include <iostream>

template <typename T, typename CTR = std::deque<T> >
class MutantStack : public std::stack<T, CTR>
{
	private:
		
	public:
		MutantStack();
		MutantStack(CTR ctr);
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();
	
		typedef typename CTR::iterator iterator;
		iterator begin(void);
		iterator end(void);
};

template <typename T>
std::ostream operator<<(std::ostream os, MutantStack<T> const &  ex);

#include "MutantStack.tpp"
