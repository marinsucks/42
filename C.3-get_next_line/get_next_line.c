/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:13 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/08 14:39:26 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*tempsplit(char *temp, char *stash)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i] != 0)
		i++;
	if (temp[i] != 0)
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	res = ft_strncpy(res, temp, i);
	while (temp[i])
		stash[j++] = temp[i++];
	free(temp);
	stash[j] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*temp;
	int			readval;

	temp = ft_strdup(stash);
	if (hasnewline(stash))
		return (tempsplit(temp, stash));
	readval = read(fd, stash, BUFFER_SIZE);
	stash[readval] = 0;
	if (readval <= 0 && temp[0] == 0)
	{
		free(temp);
		return (0);
	}
	temp = ft_strjoin(temp, stash);
	while (!hasnewline(temp) && readval > 0)
	{
		readval = read(fd, stash, BUFFER_SIZE);
		stash[readval] = 0;
		temp = ft_strjoin(temp, stash);
	}
	return (tempsplit(temp, stash));
}
