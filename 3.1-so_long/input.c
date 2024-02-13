/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:09:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/13 17:02:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keysym, t_mlx *data)
{
	data->px = get_xy(data->map, 'P') & 0x0000FFFF;
	data->py = get_xy(data->map, 'P') >> 32;
	if (keysym == XK_Escape)
		ft_quit(data);
	else if (keysym == XK_w || keysym == XK_Up)
	{
		data->dir = PUP;
		move_player(data);
	}	
	else if (keysym == XK_d || keysym == XK_Right)
	{
		data->dir = PRIGHT;
		move_player(data);
	}	
	else if (keysym == XK_s || keysym == XK_Down)
	{
		data->dir = PDOWN;
		move_player(data);
	}	
	else if (keysym == XK_a || keysym == XK_Left)
	{
		data->dir = PLEFT;
		move_player(data);
	}	
	return (0);
}
