/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:40:34 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/10 12:03:17 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_wdw(t_mlx *data, char *title, int width, int height)
{
	data->cnx = mlx_init();
	if (!data->cnx)
		return (ft_quit(data), 1);
	data->wdw = mlx_new_window(data->cnx, width * BPS, height * BPS, title);
	if (!data->wdw)
		return (ft_quit(data), 1);
	return (0);
}

void	put_map(t_mlx *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->cnx, data->wdw, data->img[0].ptr,
					j * BPS, i * BPS);
			else if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->cnx, data->wdw, data->img[1].ptr,
					j * BPS, i * BPS);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->cnx, data->wdw, data->img[2].ptr,
					j * BPS, i * BPS);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->cnx, data->wdw, data->img[3].ptr,
					j * BPS, i * BPS);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->cnx, data->wdw, data->img[4].ptr,
					j * BPS, i * BPS);
		}
	}
}
