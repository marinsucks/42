/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:55:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/30 18:00:13 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "Element not found";
		}
};

template <typename T>
int	easyfind(const T& ctr, int n)
{
	typename T::const_iterator it = std::find(ctr.begin(), ctr.end(), n);
	if (it != ctr.end())
		return (*it);
	else
		throw NotFoundException();
}
