/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:23 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/30 15:29:32 by mbecker          ###   ########.fr       */
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
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

/*
	In Big-Endian: It's stored as 12 34 56 78 in memory.

	In Little-Endian: It's stored as 78 56 34 12 in memory.

	How does this apply to graphics and MiniLibX?
	When we're dealing with colors in graphics, we often represent them using 
	multiple bytes. For example, ARGB format uses 4 bytes to represent a color: 
	one byte each for the Alpha, Red, Green, and Blue components.
	If your system is Big-Endian, the ARGB value 0x12345678 would mean the alpha value
	is 0x12, the red value is 0x34, the green value is 0x56, and the blue value is 0x78.
		DO WE CARE? NO. 👀
	Direct Memory Manipulation: While the endian value becomes critical when doing 
	direct memory manipulation byte-by-byte. 
	The manipulation is done using (unsigned int *) for the entire color value, namely the pixel. 
	This approach abstracts away the need for us to consider individual byte order for each color channel, thank god.
*/


#endif
