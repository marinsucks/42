/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/13 12:09:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_textures(t_mlx *data)
{
	int	i;

	i = 0;
	data->img[WALL].ptr = mlx_xpm_file_to_image(data->cnx, WALL_P, &i, &i);
	data->img[FLOOR].ptr = mlx_xpm_file_to_image(data->cnx, FLOOR_P, &i, &i);
	data->img[EXIT].ptr = mlx_xpm_file_to_image(data->cnx, EXIT_P, &i, &i);
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
	//while (i < SPRITES_NB && data->img[i].ptr)
	//	i++;
	//if (i != SPRITES_NB)
	//	return(write(2, "Missing sprite\n", 15), ft_quit(&data), 1); //DEBUG
	return (0);
}

//int move_player(t_mlx *data, char direction)
//{
//	long temp;
//	int x;
//	int y;

//	temp = get_xy(data->map, 'P');
//	x = temp & 0x0000FFFF;
//	y = (temp >> 32) - 1;
//	//if (direction == 'u')
	
//}
