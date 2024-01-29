/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/29 14:54:40 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include <X11/keysymdef.h>

int	handle_key(int keysym, t_mlx *data)
{
	ft_printf("the key %d has been pressed\n", keysym);
	if (keysym == 65307)
	{
		mlx_destroy_window(data->cnx, data->wdw);
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
		return (ft_free(1, data.cnx));
	data.wdw = mlx_new_window(data.cnx, 640, 480, "Hello world!");
	if (!data.wdw)
	{
		mlx_destroy_display(data.cnx);
		free(data.cnx);
		return (1);
	}
	
	
	mlx_key_hook(data.wdw, handle_key, &data);
	
	

	mlx_loop(data.cnx);
	mlx_destroy_display(data.cnx);
	free(data.cnx);
}
