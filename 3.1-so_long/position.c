/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/09 13:35:32 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Finds the coordinates (x, y) of the given element in the map.
 *
 * @param map The 2D array representing the map.
 * @param element The element to search for in the map. use 0 to get 
 * the end of the map.
 * @note returns the position of the element if found, otherwise -1.
 * @note x == result & 0xFFFFFFFF
 * @note y == result >> 32
 */
long get_xy(char **map, char element)
{
	long y;
	long x;

	y = -1; 
	if (map == NULL)
		return (-1);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == element)
				return (y << 32 | x);
		}
	}
	if (element == 0)
		return (y << 32 | x);
	return (-1);
}

//int	is_blocked()
