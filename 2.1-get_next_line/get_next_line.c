/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:13 by mbecker           #+#    #+#             */
/*   Updated: 2023/12/11 19:10:26 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	lines_read;
	char		*res;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)// || fd > OPEN_MAX)
		return (NULL);
			// open max est le nombre max de fd ouvert en même temps
	if (!(res = malloc(sizeof(char) * (BUFFER_SIZE + 1)))) 
		return (NULL);
	lines_read = 0;
	while ((ret = read(fd, res, BUFFER_SIZE)) > 0)
	{
		lines_read++;
		res[ret] = '\0';
		if (ft_strchr(res, '\n'))
			break ;
	}


	return (res);
}

