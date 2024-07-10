/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:01:32 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/14 13:04:14 by mbecker          ###   ########.fr       */
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
		move_player(data, PUP);
	else if (keysym == XK_d || keysym == XK_Right)
		move_player(data, PRIGHT);
	else if (keysym == XK_s || keysym == XK_Down)
		move_player(data, PDOWN);
	else if (keysym == XK_a || keysym == XK_Left)
		move_player(data, PLEFT);
	return (0);
}

void	move_player(t_mlx *data, int dir)
{
	data->dir = dir;
	if (data->dir == PUP && !is_blocked(data))
		update_map(data, -1, 0);
	else if (data->dir == PRIGHT && !is_blocked(data))
		update_map(data, 0, 1);
	else if (data->dir == PDOWN && !is_blocked(data))
		update_map(data, 1, 0);
	else if (data->dir == PLEFT && !is_blocked(data))
		update_map(data, 0, -1);
	animate_player(data);
}

void	update_map(t_mlx *data, int y, int x)
{
	long	exit;

	if (data->map[(data->py) + y][(data->px) + x] == 'C')
	{
		ft_printf("coin collected!\n");
		data->coinsleft--;
	}
	exit = get_xy(data->map, 'E');
	if (data->coinsleft == 0 && exit != -1)
	{
		data->map[exit >> 32][exit & 0xFFFFFFFF] = 'o';
		print_img(data, data->img[EXIT1].ptr,
			(exit & 0xFFFFFFFF) * BPS, (exit >> 32) * BPS);
		mlx_do_sync(data->cnx);
	}
	else if (data->map[(data->py) + y][(data->px) + x] == 'o')
	{
		ft_printf("You won! You collected all the \
coins in %d moves!\n", data->moves);
		ft_quit(data);
	}
	data->map[(data->py) + y][(data->px) + x] = 'P';
	data->map[data->py][data->px] = '0';
}

int	main(int ac, char **av)
{
	t_mlx	data;
	int		fd;

	fd = open(av[1], O_RDONLY);
	data = (t_mlx){NULL, NULL, {{NULL, NULL, 0, 0, 0}}, get_file(fd),
		0, 0, 0, 0, 0, 0, 0};
	if (!is_valid_map(data.map, av[1], &data) || ac <= 1)
		return (ft_quit(&data), 1);
	data.width = ft_strlen((const char *)data.map[0]) - 1;
	data.height = ft_tablen((const char **)data.map);
	display_wdw(&data, "so_long", data.width, data.height);
	set_textures(&data);
	display_map(&data);
	mlx_hook(data.wdw, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.wdw, 17, 1L << 17, ft_quit, &data);
	mlx_loop(data.cnx);
	ft_quit(&data);
}
