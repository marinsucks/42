/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/10 13:28:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures_borders(t_mlx *data, int *i)
{
	data->img[TB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/border_t.xpm", i, i);
	data->img[RB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/border_r.xpm", i, i);
	data->img[BB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/border_b.xpm", i, i);
	data->img[LB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/border_l.xpm", i, i);
	data->img[TRC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/corner_tr.xpm", i, i);
	data->img[BRC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/corner_br.xpm", i, i);
	data->img[BLC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/corner_bl.xpm", i, i);
	data->img[TLC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/corner_tl.xpm", i, i);
}

void	set_textures_player(t_mlx *data, int *i)
{
	data->img[TP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_t0.xpm", i, i);
	data->img[RP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_r0.xpm", i, i);
	data->img[BP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_b0.xpm", i, i);
	data->img[LP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_l0.xpm", i, i);
	data->img[TP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_t0.xpm", i, i);
	data->img[RP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_r0.xpm", i, i);
	data->img[BP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_b0.xpm", i, i);
	data->img[LP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pacman/pcm_l0.xpm", i, i);
}

int	set_textures(t_mlx *data)
{
	int	i;

	i = 0;
	//set_textures_player(data, &i);
	//set_textures_borders(data, &i);
	//data->img[COIN].ptr = mlx_xpm_file_to_image(data->cnx,
	//		"sprites/pacman/coin.xpm", &i, &i);
	data->img[0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pokemon/rock.xpm", &i, &i);
	data->img[1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pokemon/background.xpm", &i, &i);
	data->img[2].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pokemon/Ethan_d0.xpm", &i, &i);
	data->img[3].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pokemon/exit.xpm", &i, &i);
	data->img[4].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pokemon/pokeball.xpm", &i, &i);
	while (i < SPRITES_NB)
	{
		if (!data->img[i].ptr)
			return(write(2, "Invalid sprite\n", 15), ft_quit(&data), 1);
		i++;
	}
	return (0);
}
