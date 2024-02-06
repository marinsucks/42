/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:26:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/06 19:49:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangle(char **map)
{
	int 	i;
	size_t	width;
	
	i = 0;
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int has_elements(char **map)
{
	int i;
	int j;
	int	elements[3];

	elements[0] = 0;
	elements[1] = 0;
	elements[2] = 0;
	i = 0;
	while (map[j])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				elements[0]++;
			if (map[i][j] == 'E')
				elements[1]++;
			if (map[i][j++] == 'C')
				elements[2]++;
		}
		i++;
	}
	if (elements[0] != 1 || elements[1] != 1 || elements[2] < 1)
		return (0);
	return (1);
}

int	is_valid_map(char **map)
{
	if(!map[2] || !is_rectangle(map) || !has_elements(map))
		return (0);
	return (1);
}
//1111111111111
//10011000000C1
//1000011111001
//10P000E100001
//1111111111111
