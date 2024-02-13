/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/13 20:25:13 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/**
 * Checks if the given position is blocked in the specified direction.
 *
 * @param data The pointer to the t_mlx structure.
 * @param x The x-coordinate of the position.
 * @param y The y-coordinate of the position.
 * @param direction The direction to check ('u' for up, 'r' for right, 'd' for down, 'l' for left).
 * @return 1 if the position is blocked, 0 otherwise.
 */
int is_blocked(t_mlx *data)
{
	if (data->dir == PUP && (data->map[data->py - 1][data->px] == '1' 
		|| data->map[data->py - 1][data->px] == 'E'))
		return 1;
	else if (data->dir == PRIGHT && (data->map[data->py][data->px + 1] == '1' 
		|| data->map[data->py][data->px + 1] == 'E'))
		return 1;
	else if (data->dir == PDOWN && (data->map[data->py + 1][data->px] == '1' 
		|| data->map[data->py + 1][data->px] == 'E'))
		return 1;
	else if (data->dir == PLEFT && (data->map[data->py][data->px - 1] == '1' 
		|| data->map[data->py][data->px - 1] == 'E'))
		return 1;
	return 0;
}

void	update_map(t_mlx *data, int y, int x)
{
	long	exit;

	if (data->map[(data->py) + y][(data->px) + x] == 'C')
	{
		ft_printf("coin collected!\n");
		data->coinsleft--;
	}
	exit = get_xy(data->map, 'E');
	if (data->coinsleft == 0 && exit != -1)
	{
		data->map[exit >> 32][exit & 0xFFFFFFFF] = 'o';
		print_img(data, data->img[EXIT1].ptr,
		(exit & 0xFFFFFFFF) * BPS, (exit >> 32) * BPS);
		mlx_do_sync(data->cnx);
	}
	else if (data->map[(data->py) + y][(data->px) + x] == 'o')
	{
		ft_printf("You won! You collected all the coins in %d moves!\n", data->moves);
		ft_quit(data);
	}
	data->map[(data->py) + y][(data->px) + x] = 'P';
	data->map[data->py][data->px] = '0';
}

void	move_player(t_mlx *data)
{
	if (data->dir == PUP && !is_blocked(data))
		update_map(data, -1, 0);
	else if (data->dir == PRIGHT && !is_blocked(data))
		update_map(data, 0, 1);
	else if (data->dir == PDOWN && !is_blocked(data))
		update_map(data, 1, 0);
	else if (data->dir == PLEFT && !is_blocked(data))
		update_map(data, 0, -1);
	animate_player(data);
}
