/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"

/**
 * Retrieves the contents of a file and stores them in an allocated
 * two-dimensional array.
 *
 * @param fd The file descriptor of the file to read.
 * @return a two-dimensional array containing the lines of the file,
 * or NULL if an error occurred.
 */
char	**get_file(int fd)
{
	char	**res;
	char	*line;

	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * 2);
	if (!res)
		return (NULL);
	res[0] = line;
	res[1] = NULL;
	while (line)
	{
		line = get_next_line(fd);
		res = ft_tabjoin(res, line, TRUE, TRUE);
	}
	return (res);
}
