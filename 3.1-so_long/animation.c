/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:39:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/13 18:57:22 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	run_anim(t_mlx *data, int *x, int *y, int i)
{
	while (i < BPS / 2)
	{
		if (data->dir == PUP)
			*y -= 2;
		else if (data->dir == PRIGHT)
			*x += 2;
		else if (data->dir == PDOWN)
			*y += 2;
		else if (data->dir == PLEFT)
			*x -= 2;
		ft_printf("*x: %d, *y: %d\n", *x, *y);
		if (i % 2 == 0)
            print_img(data, data->img[data->dir].ptr, *x, *y);
        else if ((i - 1) % 4 == 0 ) 
            print_img(data, data->img[data->dir + 1].ptr, *x, *y);
        else
            print_img(data, data->img[data->dir + 2].ptr, *x, *y);
		mlx_do_sync(data->cnx);
		usleep(10000);
        i++;
	}
}
int	animate_player(void *dataptr)
{
	t_mlx	*data;
	int 	x;
	int 	y;
	int 	i;

	data = (t_mlx *)dataptr;
	x = data->px * BPS;
	y = data->py * BPS;
	i = 0;
	print_img(data, data->img[data->dir].ptr, x, y);
	mlx_do_sync(data->cnx);
	if (is_blocked(data))
		return 0;	
	run_anim(data, &x, &y, i); // pb here
	print_img(data, data->img[data->dir].ptr, x, y);
	mlx_do_sync(data->cnx);
	return (0);
}
