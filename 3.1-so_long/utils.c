/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/14 13:13:07 by mbecker          ###   ########.fr       */
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
long	get_xy(char **map, char element)
{
	long	y;
	long	x;

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

/**
 * Checks if the given position is blocked in the specified direction.
 * @return 1 if the position is blocked, 0 otherwise.
 */
int	is_blocked(t_mlx *data)
{
	if (data->dir == PUP && (data->map[data->py - 1][data->px] == '1'
		|| data->map[data->py - 1][data->px] == 'E'))
		return (1);
	else if (data->dir == PRIGHT && (data->map[data->py][data->px + 1] == '1'
		|| data->map[data->py][data->px + 1] == 'E'))
		return (1);
	else if (data->dir == PDOWN && (data->map[data->py + 1][data->px] == '1'
		|| data->map[data->py + 1][data->px] == 'E'))
		return (1);
	else if (data->dir == PLEFT && (data->map[data->py][data->px - 1] == '1'
		|| data->map[data->py][data->px - 1] == 'E'))
		return (1);
	return (0);
}

int	print_img(t_mlx *data, void *imgptr, int x, int y)
{
	return (mlx_put_image_to_window(data->cnx, data->wdw, imgptr, x, y));
}
