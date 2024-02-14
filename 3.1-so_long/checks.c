/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/14 14:43:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int		i;
	int		lastline;
	size_t	width;

	i = 0;
	width = ft_strlen(map[0]) - 1;
	lastline = ft_tablen((const char **)map) - 1;
	while (map[i])
	{
		if (i != lastline && ft_strlen(map[i]) - 1 != width)
			return (0);
		else if (i == lastline && ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	has_valid_elements(char **map, t_checks *ctnt)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				ctnt->count_p++;
			if (map[i][j] == 'E')
				ctnt->count_e++;
			if (map[i][j] == 'C')
				ctnt->count_c++;
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
				return (0);
		}
	}
	if (ctnt->count_p != 1 || ctnt->count_e != 1 || ctnt->count_c < 1)
		return (0);
	return (1);
}

int	is_valid_line(char **line, int i, int wall)
{
	int	j;

	j = 0;
	if (line[i][j] != '1')
		return (0);
	while (line[i][++j] && wall)
	{
		if (line[i][j] != '1')
			return (0);
		if (line[i][j + 1] == '\n' || line[i][j + 1] == 0)
			return (1);
	}
	while (line[i][++j] && !wall)
	{
		if (line[i][j] == '1' && line[i][j + 1] != '\n')
			j++;
		if (line[i][j] == '1' && line[i][j + 1] == '\n')
			return (1);
		if (line[i][j] == 'C' || ((line[i][j] == 'E' && line[i][j + 1] != '~')
			&& (line[i][j] == 'E' && line[i][j - 1] != '~')
			&& (line[i][j] == 'E' && line[i - 1][j] != '~')
			&& (line[i][j] == 'E' && line[i + 1][j] != '~')))
			return (0);
	}
	return (0);
}

int	has_valid_path(char **map, t_checks *ctnt)
{
	size_t		i;
	long		p;

	p = get_xy(map, 'P');
	ctnt->dfsmap = ft_tabdup(map);
	ft_dfs(ctnt->dfsmap, p >> 32, p & 0xFFFFFFFF, "0PC");
	i = -1;
	while (ctnt->dfsmap[++i])
	{
		if ((i == 0 || i == ft_tablen((const char **)ctnt->dfsmap) - 1)
			&& !is_valid_line(ctnt->dfsmap, i, TRUE))
			return (ft_freetab(ctnt->dfsmap, 1), 0);
		else if (!(i == 0 || i == ft_tablen((const char **)ctnt->dfsmap) - 1)
			&& !is_valid_line(ctnt->dfsmap, i, FALSE))
			return (ft_freetab(ctnt->dfsmap, 1), 0);
	}
	return (ft_freetab(ctnt->dfsmap, 1), 1);
}

int	is_valid_map(char **map, char *fname, t_mlx *data)
{
	t_checks	ctnt;

	if (!map || ft_strcmp(".ber", fname + ft_strlen(fname) - 4))
		return (write(2, MISSING, 53), 0);
	else if (ft_tablen((const char **)map) <= 2)
		return (write(2, TOO_SMALL, 35), 0);
	else if (!is_rectangle(map))
		return (write(2, NOT_RECT, 41), 0);
	ctnt = (t_checks){0, 0, 0, NULL};
	if (!has_valid_elements(map, &ctnt))
		return (write(2, "Error\n\033[0;31mMap has either invalid, too many or\
 too few elements.\033[0m\n", 71), 0);
	data->coinsleft = ctnt.count_c;
	if (!has_valid_path(map, &ctnt))
		return (write(2, BAD_PATH, 49), 0);
	return (1);
}
