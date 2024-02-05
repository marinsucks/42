/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/05 17:47:50 by mbecker          ###   ########.fr       */
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

int	handle_key(int keysym, t_mlx *data)
{
	static int	i = 0;
	if (keysym >= 0 && keysym <= 255)
		ft_printf("the key %d (%c) has been pressed\n", keysym, keysym);
	else
		ft_printf("the key %d has been pressed\n", keysym);


	if (keysym == XK_space)
		mlx_put_image_to_window(data->cnx, data->wdw, data->img[i++].ptr, 0, 0);


	if (keysym == XK_Escape)
		ft_quit(data);
	return (0);
}

int	main(void)
{
	t_mlx	data;

	//check args : valid map etc.
	ft_printf("start\n"); //DEBUG
	data.cnx = mlx_init();
	if (!data.cnx)
		return (free(data.cnx), 1);
	ft_printf("data.cnx ok\n"); //DEBUG
	data.wdw = mlx_new_window(data.cnx, 640, 480, "Hello world!");
	if (!data.wdw)
		return (mlx_destroy_display(data.cnx), free(data.cnx), 1);
	ft_printf("data.wdw ok\n"); //DEBUG

	set_textures(&data);

	//draw_map(&data, "maps/map.ber");
	mlx_key_hook(data.wdw, handle_key, &data);
	mlx_hook(data.wdw, 17, 1L << 17, ft_quit, &data);
	mlx_loop(data.cnx);
	ft_quit(&data);
}
