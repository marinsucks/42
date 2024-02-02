/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:23 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/02 16:06:30 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/***** INCLUDES *****/
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

/***** DEFINES *****/
# define MALLOC_ERR	1
# define WWIDTH 	640
# define WHEIGHT	480


/***** TYPEDEFS & STRUCTS *****/
//a byte. 8 bits.
typedef unsigned char	t_byte;

/*
 * line_len
 * `void *`	img_ptr;
 * `char *`	img_pixels_ptr;
 * `int`	bits_per_pixel;
 * `int`	endian;
 * `int`	line_len; //necessary due to alignment optimization.
*/
typedef struct s_img
{
	void	*ptr;
	char	*pxls_ptr;
	int		bits_per_pxl;
	int		endian;
	int		line_len;
}				t_img;

/** 
 * - `void *`	cnx;
 * - `void *`	wdw;
 * - `t_img`	img;
*/
typedef struct s_mlx
{
	void	*cnx;
	void	*wdw;
	t_img	img;

}			t_mlx;

/***** FUNCTIONS *****/
//mlx_utils.c
int		encode_rgb(t_byte red, t_byte green, t_byte blue);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	color_fill(t_mlx *data, int color, int x, int y);




#endif
