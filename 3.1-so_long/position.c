/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/08 17:14:53 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Finds the coordinates (x, y) of the given element in the map.
 *
 * @param map The 2D array representing the map.
 * @param element The element to search for in the map.
 * @return the position of the element if found, otherwise -1.
 * @note get_xy(map, element) >> 32; = i 
 * @note get_xy(map, element) & 0xFFFFFFFF; = j
 */
long get_xy(char **map, char element)
{
	long i;
	long j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == element)
				return (i << 32 | j);
		}
	}
	return (-1);
}