/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:09:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/12 12:41:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keysym, t_mlx *data)
{
	//static int i = 0;//TESTS
	//if (i == SPRITES_NB)
	//	i = 0;
	
	//static int j = 0;

	if (keysym >= 0 && keysym <= 255)
		ft_printf("the key %d (%c) has been pressed\n", keysym, keysym);
	else
		ft_printf("the key %d has been pressed\n", keysym);
	if (keysym == XK_Escape)
		ft_quit(data);

	//if (keysym == XK_space)
	//	mlx_put_image_to_window(data->cnx, data->wdw, data->img[i++].ptr, j++, 0);//TESTS
	

	return (0);
}
