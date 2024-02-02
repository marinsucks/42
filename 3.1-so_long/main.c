/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/02 15:53:11 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(void *data)
{
	if (!data)
		exit(0);
	if (((t_mlx *)data)->img.ptr)
		mlx_destroy_image(((t_mlx *)data)->cnx, ((t_mlx *)data)->img.ptr);
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
	if (keysym >= 0 && keysym <= 255)
		ft_printf("the key %d (%c) has been pressed\n", keysym, keysym);
	else
		ft_printf("the key %d has been pressed\n", keysym);

	if (keysym == XK_space)
		mlx_put_image_to_window(data->cnx, data->wdw, data->img.ptr, 0, 0);

	if (keysym == XK_Escape)
		ft_quit(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_mlx *data)
{
	ft_printf("the button %d has been pressed at %d, %d\n", button, x, y);
	if (button == 1)
		ft_quit(data);
	return (0);
}

int	main(void)
{
	t_mlx	data;

	data.cnx = mlx_init();
	if (!data.cnx)
		return (free(data.cnx), 1);
	data.wdw = mlx_new_window(data.cnx, 640, 480, "Hello world!");
	if (!data.wdw)
		return (mlx_destroy_display(data.cnx), free(data.cnx), 1);

	int x = 32;
	int y = 24;
	data.img.ptr = mlx_xpm_file_to_image(data.cnx, "textures/pacman/Arcade - Pac-Man - General Sprites.xpm", &x, &y);
	if (!data.img.ptr)
		return (ft_quit(&data), 1);

	mlx_key_hook(data.wdw, handle_key, &data);
	mlx_hook(data.wdw, 17, 1L << 17, ft_quit, &data);
	mlx_loop(data.cnx);
	ft_quit(&data);
}
