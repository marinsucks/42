/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:56:13 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/10 11:34:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(void *vdata)
{
	int i;
	t_mlx *data;

	i = -1;
	if (!vdata)
		exit(0);
	data = (t_mlx *)vdata;
	if (data->map)
		ft_freetab(data->map, TRUE);
	while (++i < SPRITES_NB)
	{
		if (data->img[i].ptr)
			mlx_destroy_image(data->cnx, data->img[i].ptr);
	}
	if (data->wdw)
		mlx_destroy_window(data->cnx, data->wdw);
	if (data->cnx)
	{		
		mlx_destroy_display(data->cnx);
		free(data->cnx);
	}
	exit(0);
	return (0);
}
