/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/06 20:17:16 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(void *data)
{
	int i;

	i = 0;
	if (!data)
		exit(0);
	while (i < SPRITES_NB)
	{
		if (((t_mlx *)data)->img[i].ptr)
			mlx_destroy_image(((t_mlx *)data)->cnx, 
				((t_mlx *)data)->img[i].ptr);
		i++;
	}
	if (((t_mlx *)data)->wdw && ((t_mlx *)data)->cnx)
	{
		mlx_destroy_window(((t_mlx *)data)->cnx, ((t_mlx *)data)->wdw);
		mlx_destroy_display(((t_mlx *)data)->cnx);
		free(((t_mlx *)data)->cnx);
	}
	exit(0);
	return (0);
}

int	main()//int ac, char **av)
{
	//t_mlx	data;
	//char 	**map;

	//map = getmap(av[1]); 
	//if (!map)
	//	return (1);
	//ft_printf("start\n"); //DEBUG
	//data.cnx = mlx_init();
	//if (!data.cnx)
	//	return (free(data.cnx), 1);
	//ft_printf("data.cnx ok\n"); //DEBUG
	//data.wdw = mlx_new_window(data.cnx, 640, 480, "Hello world!");
	//if (!data.wdw)
	//	return (mlx_destroy_display(data.cnx), free(data.cnx), 1);
	//ft_printf("data.wdw ok\n"); //DEBUG

	//set_textures(&data);

	//draw_map(&data, "maps/map.ber");
	//mlx_key_hook(data.wdw, handle_key, &data);
	//mlx_hook(data.wdw, 17, 1L << 17, ft_quit, &data);
	//mlx_loop(data.cnx);
	//ft_quit(&data);
}
