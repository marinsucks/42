/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/09 13:03:49 by mbecker          ###   ########.fr       */
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

int	is_valid_line(char *line, int wall)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	while (line[++i] && wall)
	{
		if (line[i] != '1')
			return (0);
		if (line[i + 1] == '\n' || line[i + 1] == 0)
			return (1);
	}
	while (line[++i] && !wall)
	{
		if (line[i] == '1' && line[i + 1] != '\n')
			i++;
		else if (line[i] == '1' && line[i + 1] == '\n')
			return (1);
		if (line[i] == 'C' || line[i] == 'E')
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
	ft_dfs(ctnt->dfsmap, p >> 32, p & 0xFFFFFFFF, "0PEC");
	i = -1;
	while (ctnt->dfsmap[++i])
	{
		if ((i == 0 || i == ft_tablen((const char **)ctnt->dfsmap) - 1)
			&& !is_valid_line(ctnt->dfsmap[i], TRUE))
			return (0);
		else if (!(i == 0 || i == ft_tablen((const char **)ctnt->dfsmap) - 1)
			&& !is_valid_line(ctnt->dfsmap[i], FALSE))
			return (0);
	}
	ft_freetab(ctnt->dfsmap, 1);
	return (1);
}

int	is_valid_map(char **map)
{
	t_checks	ctnt;

	if (!map)
		return (write(2, "\033[0;31mError: map is missing or empty.\
\033[0m\n", 43), 0);
	else if (ft_tablen((const char **)map) <= 2)
		return (write(2, "\033[0;31mError: map is too small.\
\033[0m\n", 36), 0);
	else if (!is_rectangle(map))
		return (write(2, "\033[0;31mError: map isn't a rectangle.\
\033[0m\n", 41), 0);
	ctnt = (t_checks){'P', 'E', 'C', '1', '0', 0, 0, 0, NULL};
	if (!has_valid_elements(map, &ctnt))
		return (write(2, "\033[0;31mError: map has either invalid, \
too many or too few elements.\033[0m\n", 72), 0);
	if (!has_valid_path(map, &ctnt))
		return (write(2, "\033[0;31mError: map has no valid path or has holes.\
\033[0m\n", 54), 0);
	return (1);
}
