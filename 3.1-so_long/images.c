/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:59:39 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/06 16:01:07 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures_borders(t_mlx *data, int *i)
{
	data->img[TB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/border_t.xpm", i, i);
	data->img[RB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/border_r.xpm", i, i);
	data->img[BB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/border_b.xpm", i, i);
	data->img[LB].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/border_l.xpm", i, i);
	data->img[TRC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/corner_tr.xpm", i, i);
	data->img[BRC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/corner_br.xpm", i, i);
	data->img[BLC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/corner_bl.xpm", i, i);
	data->img[TLC].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/corner_tl.xpm", i, i);
}

void	set_textures_player(t_mlx *data, int *i)
{
	data->img[TP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_t0.xpm", i, i);
	data->img[RP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_r0.xpm", i, i);
	data->img[BP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_b0.xpm", i, i);
	data->img[LP0].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_l0.xpm", i, i);
	data->img[TP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_t0.xpm", i, i);
	data->img[RP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_r0.xpm", i, i);
	data->img[BP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_b0.xpm", i, i);
	data->img[LP1].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/pcm_l0.xpm", i, i);
}

void	set_textures(t_mlx *data)
{
	int	i;

	i = 0;
	set_textures_player(data, &i);
	set_textures_borders(data, &i);
	data->img[COIN].ptr = mlx_xpm_file_to_image(data->cnx,
			"sprites/pcm/coin.xpm", &i, &i);
	while (i < SPRITES_NB)
	{
		if (!data->img[i].ptr)
			ft_quit(&data);
		i++;
	}
}
