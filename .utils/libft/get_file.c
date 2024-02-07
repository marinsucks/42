/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:57:10 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/07 13:39:45 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Retrieves the contents of a file and stores them in a two-dimensional array.
 *
 * @param fd The file descriptor of the file to read.
 * @return a two-dimensional array containing the lines of the file, or NULL if an error occurred.
 */
char **get_file(int fd)
{
	char **res;
	char *line;
	char *tmp;
	int count;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	count = 1;
	while (line)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		line = ft_strjoin(line, tmp, TRUE, TRUE);
		count++;
	}
	res = ft_split(line, '\n');
	free(line);
	return (res);
}
