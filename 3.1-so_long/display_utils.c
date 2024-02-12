/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/12 13:25:55 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_textures(t_mlx *data)
{
	int	i;

	i = 0;
	data->WALL = mlx_xpm_file_to_image(data->cnx, WALL_PATH, &i, &i);
	data->FLOOR = mlx_xpm_file_to_image(data->cnx, FLOOR_PATH, &i, &i);
	data->EXIT = mlx_xpm_file_to_image(data->cnx, EXIT_PATH, &i, &i);
	data->COIN = mlx_xpm_file_to_image(data->cnx, COIN_PATH, &i, &i);
	data->PDOWN = mlx_xpm_file_to_image(data->cnx, PD_PATH, &i, &i);
	data->PDOWN1 = mlx_xpm_file_to_image(data->cnx, PD1_PATH, &i, &i);
	data->PDOWN2 = mlx_xpm_file_to_image(data->cnx, PD2_PATH, &i, &i);
	data->PRIGHT = mlx_xpm_file_to_image(data->cnx, PR_PATH, &i, &i);
	data->PRIGHT1 = mlx_xpm_file_to_image(data->cnx, PR1_PATH, &i, &i);
	data->PRIGHT2 = mlx_xpm_file_to_image(data->cnx, PR2_PATH, &i, &i);
	data->PUP = mlx_xpm_file_to_image(data->cnx, PU_PATH, &i, &i);
	data->PUP1 = mlx_xpm_file_to_image(data->cnx, PU1_PATH, &i, &i);
	data->PUP2 = mlx_xpm_file_to_image(data->cnx, PU2_PATH, &i, &i);
	data->PLEFT = mlx_xpm_file_to_image(data->cnx, PL_PATH, &i, &i);
	data->PLEFT1 = mlx_xpm_file_to_image(data->cnx, PL1_PATH, &i, &i);
	data->PLEFT2 = mlx_xpm_file_to_image(data->cnx, PL2_PATH, &i, &i);
	//while (i < SPRITES_NB && data->img[i].ptr)
	//	i++;
	//if (i != SPRITES_NB)
	//	return(write(2, "Missing sprite\n", 15), ft_quit(&data), 1); //DEBUG
	return (0);
}

int move_player(t_mlx *data, char direction)
{
	long temp;
	int x;
	int y;

	temp = get_xy(data->map, 'P');
	x = temp & 0x0000FFFF;
	y = (temp >> 32) - 1;
	//if (direction == 'u')
	
}
