/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:40:34 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/05 15:10:39 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_mlx *data, char *map)
{
	int		i;
	//int		j;
	int		fd;
	char	*tab[WHEIGHT / 8];

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_quit(data);
	tab[0] = get_next_line(fd);
	while (tab[i++])
		tab[i] = get_next_line(fd);



	ft_freetab(tab, FALSE);
}
