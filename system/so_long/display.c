/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:40:34 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/14 15:33:38 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_wdw(t_mlx *data, char *title, int width, int height)
{
	data->cnx = mlx_init();
	if (!data->cnx)
		return (ft_quit(data), 1);
	data->wdw = mlx_new_window(data->cnx, width * BPS, height * BPS, title);
	if (!data->wdw)
		return (ft_quit(data), 1);
	return (0);
}

int	set_textures(t_mlx *data)
{
	int	i;

	i = 0;
	data->img[WALL].ptr = mlx_xpm_file_to_image(data->cnx, WALL_P, &i, &i);
	data->img[FLOOR].ptr = mlx_xpm_file_to_image(data->cnx, FLOOR_P, &i, &i);
	data->img[EXIT1].ptr = mlx_xpm_file_to_image(data->cnx, EXIT1_P, &i, &i);
	data->img[EXIT2].ptr = mlx_xpm_file_to_image(data->cnx, EXIT2_P, &i, &i);
	data->img[COIN].ptr = mlx_xpm_file_to_image(data->cnx, COIN_P, &i, &i);
	data->img[PDOWN].ptr = mlx_xpm_file_to_image(data->cnx, PD_P, &i, &i);
	data->img[PDOWN1].ptr = mlx_xpm_file_to_image(data->cnx, PD1_P, &i, &i);
	data->img[PDOWN2].ptr = mlx_xpm_file_to_image(data->cnx, PD2_P, &i, &i);
	data->img[PRIGHT].ptr = mlx_xpm_file_to_image(data->cnx, PR_P, &i, &i);
	data->img[PRIGHT1].ptr = mlx_xpm_file_to_image(data->cnx, PR1_P, &i, &i);
	data->img[PRIGHT2].ptr = mlx_xpm_file_to_image(data->cnx, PR2_P, &i, &i);
	data->img[PUP].ptr = mlx_xpm_file_to_image(data->cnx, PU_P, &i, &i);
	data->img[PUP1].ptr = mlx_xpm_file_to_image(data->cnx, PU1_P, &i, &i);
	data->img[PUP2].ptr = mlx_xpm_file_to_image(data->cnx, PU2_P, &i, &i);
	data->img[PLEFT].ptr = mlx_xpm_file_to_image(data->cnx, PL_P, &i, &i);
	data->img[PLEFT1].ptr = mlx_xpm_file_to_image(data->cnx, PL1_P, &i, &i);
	data->img[PLEFT2].ptr = mlx_xpm_file_to_image(data->cnx, PL2_P, &i, &i);
	return (0);
}

void	display_map(t_mlx *data)
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
				print_img(data, data->img[WALL].ptr, j * BPS, i * BPS);
			else if (data->map[i][j] == '0')
				print_img(data, data->img[FLOOR].ptr, j * BPS, i * BPS);
			else if (data->map[i][j] == 'P')
				print_img(data, data->img[PDOWN].ptr, j * BPS, i * BPS);
			else if (data->map[i][j] == 'E')
				print_img(data, data->img[EXIT2].ptr, j * BPS, i * BPS);
			else if (data->map[i][j] == 'C')
				print_img(data, data->img[COIN].ptr, j * BPS, i * BPS);
		}
	}
}

void	animate_player(void *dataptr)
{
	t_mlx	*data;
	int		x;
	int		y;
	int		i;

	data = (t_mlx *)dataptr;
	x = data->px * BPS;
	y = data->py * BPS;
	i = 0;
	print_img(data, data->img[data->dir].ptr, x, y);
	mlx_do_sync(data->cnx);
	if (is_blocked(data))
		return ;
	run_player_animation(data, &x, &y, i);
	ft_printf("moves count: %d\n", ++data->moves);
	print_img(data, data->img[data->dir].ptr, x, y);
	mlx_do_sync(data->cnx);
}

void	run_player_animation(t_mlx *data, int *x, int *y, int i)
{
	while (i < BPS / 2)
	{
		if (data->dir == PUP)
			*y -= 2;
		else if (data->dir == PRIGHT)
			*x += 2;
		else if (data->dir == PDOWN)
			*y += 2;
		else if (data->dir == PLEFT)
			*x -= 2;
		if (i % 2 == 0)
			print_img(data, data->img[data->dir].ptr, *x, *y);
		else if ((i - 1) % 4 == 0)
			print_img(data, data->img[data->dir + 1].ptr, *x, *y);
		else
			print_img(data, data->img[data->dir + 2].ptr, *x, *y);
		mlx_do_sync(data->cnx);
		usleep(10000);
		i++;
	}
}
