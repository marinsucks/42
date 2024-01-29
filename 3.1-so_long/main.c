/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/29 16:38:07 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keysym, t_mlx *data)
{
	if (keysym >= 0 && keysym <= 255)
		ft_printf("the key %d (%c) has been pressed\n", keysym, keysym);
	else
		ft_printf("the key %d has been pressed\n", keysym);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->cnx, data->wdw);
		mlx_destroy_display(data->cnx);
		free(data->cnx);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_mlx	data;

	data.cnx = mlx_init();
	if (!data.cnx)
	{
		free(data.cnx);
		return (1);
	}
	data.wdw = mlx_new_window(data.cnx, 640, 480, "Hello world!");
	if (!data.wdw)
	{
		mlx_destroy_display(data.cnx);
		free(data.cnx);
		return (1);
	}
	
//	mlx_string_put(data.cnx, data.wdw, 50, 50, 0x00FFFFFF, "\033[1;31mHello world!");
	mlx_key_hook(data.wdw, handle_key, &data);
	
	

	mlx_loop(data.cnx);
	mlx_destroy_display(data.cnx);
	free(data.cnx);
}
