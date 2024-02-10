/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/10 11:39:35 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	data;
	int		fd;

	//get map and set data.
	fd = open(av[1], O_RDONLY);
	data = (t_mlx){NULL, NULL, {{NULL, NULL, 0, 0, 0}}, get_file(fd), 0};

	//make checks
	if (!is_valid_map(data.map, av[1]) || ac <= 1)
		return (ft_quit(&data), 1);
	data.xy = get_xy(data.map, 0);

	//start a window
	put_wdw(&data, "so_long", data.xy & 0xFFFFFFFF, data.xy >> 32);

	//Ask for preferences, store them in data.wasd and data.theme.
	//get_preferences(&data);
		//set_sprites(&data);
	//draw_map(&data, "maps/map.ber");

	mlx_key_hook(data.wdw, handle_key, &data);
	mlx_hook(data.wdw, 17, 1L << 17, ft_quit, &data);
	mlx_loop(data.cnx);
	ft_quit(&data);
}
