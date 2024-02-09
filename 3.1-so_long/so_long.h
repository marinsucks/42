/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:23 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/09 17:11:47 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/***** INCLUDES *****/
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "libft/libft.h"
# include "defines.h"

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>

/***** DEFINES *****/
# define MALLOC_ERR	1


/***** TYPEDEFS & STRUCTS *****/
//a byte. 8 bits.
typedef unsigned char	t_byte;

/*
 * line_len
 * `void *`	img_ptr;
 * `char *`	img_pixels_ptr;
 * `int`	bpp; //bits per pixel
 * `int`	endian;
 * `int`	line_len; //necessary due to alignment optimization.
*/
typedef struct s_img
{
	void	*ptr;
	char	*pxls_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

/** 
 * - `void *`	cnx;
 * - `void *`	wdw;
 * - `t_img`	img[SPRITES_NB];
 * - `char **`	map;
 * - `long`		xy;
*/
typedef struct s_mlx
{
	void	*cnx;
	void	*wdw;
	t_img	img[SPRITES_NB];
	char	**map;
	long	xy;
}			t_mlx;

/**
 * - `char` player;
 * - `char` exit;
 * - `char` coin;
 * - `char` wall;
 * - `char` floor;
 * - `int` count_p;
 * - `int` count_e;
 * - `int` count_c;
 * - `char **` visited;
*/
typedef struct s_checks
{
	char	player;
	char	exit;
	char	coin;
	char	wall;
	char	floor;
	int		count_p;
	int		count_e;
	int		count_c;
	char	**dfsmap;
}			t_checks;

/***** FUNCTIONS *****/

int		ft_quit(void *data);
int		handle_key(int keysym, t_mlx *data);
//main.c

int	is_valid_map(char **map, char *fname);
//parsing.c

void	set_textures(t_mlx *data);
//images.c

void	draw_map(t_mlx *data, int fd);
//map.c

int	handle_key(int keysym, t_mlx *data);
//keys.c

long	get_xy(char **map, char element);
//position.c

int		encode_rgb(t_byte red, t_byte green, t_byte blue);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	color_fill(t_mlx *data, int color, int x, int y);
//mlx_utils.c

#endif
