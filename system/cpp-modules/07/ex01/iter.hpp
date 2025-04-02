/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:59 by mbecker           #+#    #+#             */
/*   Updated: 2024/12/13 14:43:59 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	iter(T* array, long len, void (*func)(T&))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

template <typename T>
void	iter(const T* array, long len, void (*func)(const T&))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}
