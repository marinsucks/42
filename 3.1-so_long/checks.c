/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/07 16:41:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	is_rectangle(char **map)
{
	int		i;
	size_t	width;

	i = 0;
	width = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) - 1 != width)
			return (0);
		i++;
	}
	if (ft_strlen(map[i - 1]) - 1 != width)
		return (0);
	return (1);
}

int	has_correct_elements(char **map, t_checks *ctnt)
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
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')//DEBUG : j++ here
				return (0);
		}
	}
	ft_printf("i = %d, j = %d\n", i, j);
	if (map[--i][--j] == '\n')
		ft_printf("map [--i][j] = \\n\n");
	if (map[i][j] == 0)
		ft_printf("map [--i][j] = \\0\n");
	else
		ft_printf("map [--i][j] = %c\n", map[i][j]);
	
	if (ctnt->count_p != 1 || ctnt->count_e != 1 || ctnt->count_c < 1)// || map[i - 1][j] == '\n')
		return (0);
	return (1);
}

int	is_valid_map(char **map)
{
	t_checks	ctnt;

	ctnt = (t_checks){'P', 'E', 'C', '1', '0', 0, 0, 0};
	if (!map)
		return (write(1, "Error: map is missing or empty.\n", 32), 0);
	else if (ft_tablen((const char **)map) <= 2)
		return (write(1, "Error: map is too small.\n", 25), 0);
	else if (!is_rectangle(map))
		return (write(1, "Error: map isn't a rectangle.\n", 30), 0);
	else if (!has_correct_elements(map, &ctnt))
		return (write(1, "Error: \
map has either incorrect, too many or too few elements.\n", 63), 0);
	return (1);
}

int	main(void)
{
	int		fd;
	char	**map;

	char *mapnames[] = {
		////MISSING
		//"tests/empty.ber",

		////TOO SMALL
		//"tests/oneclmn.ber",
		//"tests/onecorner.ber",
		//"tests/onewall.ber",
		//"tests/twowalls.ber",

		////NOT RECTANGLE
		//"tests/notrect.ber",
		//"tests/notrect2.ber",
		"tests/withnl.ber",

		////HAS HOLES
		//"tests/badlftwall.ber",
		//"tests/badbtmwall.ber",
		//"tests/badrgtwall.ber",
		//"tests/badtopwall.ber",
		
		////ELEMENTS
		//"tests/noC.ber",
		//"tests/noE.ber",
		//"tests/noP.ber",
		//"tests/noPEC.ber",
		//"tests/invalidchar.ber",

		////PATH
		//"tests/nopath.ber",

		////OK
		//"tests/ok.ber",
		//"tests/ok2.ber",

		NULL
						};
	for (size_t i = 0; mapnames[i]; i++)
	{
		ft_printf("\nTEST %s\n", mapnames[i] + 6);
		fd = open(mapnames[i], O_RDONLY);
		map = get_file(fd);
		if (!map)
		{
			ft_printf("%p\n", map);
			is_valid_map(map);
		}
		else
		{
			for (size_t i = 0; map[i]; i++)
				ft_printf("%s", map[i]);
			is_valid_map(map);
		}
		if (map)
			ft_freetab(map, 1);
	}
}
