/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:09:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/06 16:09:48 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keysym, t_mlx *data)
{
	static int i = 0;
	if (i == SPRITES_NB)
		i = 0;
	if (keysym >= 0 && keysym <= 255)
		ft_printf("the key %d (%c) has been pressed\n", keysym, keysym);
	else
		ft_printf("the key %d has been pressed\n", keysym);


	if (keysym == 'q')
		mlx_put_image_to_window(data->cnx, data->wdw, data->img[i++].ptr, 0, 0);
	if (keysym == 'w')
		mlx_put_image_to_window(data->cnx, data->wdw, data->img[i++].ptr, 32, 0);
	if (keysym == 'e')
		mlx_put_image_to_window(data->cnx, data->wdw, data->img[i++].ptr, 64, 0);
	if (keysym == 'r')
		mlx_put_image_to_window(data->cnx, data->wdw, data->img[i++].ptr, 96, 0);
	


	if (keysym == XK_Escape)
		ft_quit(data);
	return (0);
}
