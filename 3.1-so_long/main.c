/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/13 16:46:27 by mbecker          ###   ########.fr       */
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

int frames(void *ptr)
{
	t_mlx	*data;

	data = (t_mlx *)ptr;
	if (data->img[PDOWN].ptr)
		mlx_put_image_to_window(data->cnx, data->wdw, data->img[PDOWN].ptr, 0, 0);
	return (0);

}

int	main(int ac, char **av)
{
	t_mlx	data;
	int		fd;

	// get map and set data.
	fd = open(av[1], O_RDONLY);
	data = (t_mlx){NULL, NULL, {{NULL, NULL, 0, 0, 0}}, get_file(fd),
		0, 0, 0, 0, 0, 0};

	// make checks
	if (!is_valid_map(data.map, av[1], &data) || ac <= 1)
		return (ft_quit(&data), 1);
	data.width = ft_strlen((const char *)data.map[0]) - 1;
	data.height = ft_tablen((const char **)data.map);

	// start a window
	put_wdw(&data, "so_long", data.width, data.height);
	set_textures(&data);
	put_map(&data);
	mlx_key_hook(data.wdw, handle_key, &data);
	mlx_hook(data.wdw, 17, 1L << 17, ft_quit, &data);
	mlx_loop(data.cnx);
	ft_quit(&data);
}
