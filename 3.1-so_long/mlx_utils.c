/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:28:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/02 15:53:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// @returns an int equal in bin as `00000000rrrrrrrrggggggggbbbbbbbb`
int	encode_rgb(t_byte red, t_byte green, t_byte blue)
{
	return (red << 16 | green << 8 | blue);
}

/*
 * Faster version of mlx_pixel_put. Works with t_img struct.
 * See https://github.com/suspectedoceano/mlx
 */
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = (img->line_len * y) + (x * (img->bits_per_pxl / 8));
	*((unsigned int *)(pixel + img->pxls_ptr)) = color;
}

/**
 * @brief Fills a rectangular area of the screen with a specified color, 
 * from x to WWIDTH and fromy to WHEIGHT.
 * 
 * @param data The mlx data structure. Must contain an initialized img struct.
 * @param color The color to fill the area with.
 * @param x The starting x-coordinate of the area.
 * @param y The starting y-coordinate of the area.
 */
void	color_fill(t_mlx *data, int color, int x, int y)
{
	while (y < WHEIGHT)
	{
		while (x < WWIDTH)
		{
			my_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
}
