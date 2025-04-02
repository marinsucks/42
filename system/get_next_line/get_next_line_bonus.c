/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:37:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/08 14:39:04 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_fd_data	*get_fd_data(int fd)
{
	static t_fd_data	fd_data[FD_MAX];
	int					i;

	i = 0;
	while (i < FD_MAX)
	{
		if (fd_data[i].fd == fd)
			return (&fd_data[i]);
		if (fd_data[i].fd == 0)
		{
			fd_data[i].fd = fd;
			return (&fd_data[i]);
		}
		i++;
	}
	return (NULL);
}

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
	t_fd_data	*fd_data;
	char		*temp;
	int			readval;

	fd_data = get_fd_data(fd);
	if (!fd_data)
		return (NULL);
	temp = ft_strdup(fd_data->stash);
	if (hasnewline(fd_data->stash))
		return (tempsplit(temp, fd_data->stash));
	readval = read(fd, fd_data->stash, BUFFER_SIZE);
	fd_data->stash[readval] = 0;
	if (readval <= 0 && temp[0] == 0)
	{
		free(temp);
		return (NULL);
	}
	temp = ft_strjoin(temp, fd_data->stash);
	while (!hasnewline(temp) && readval > 0)
	{
		readval = read(fd, fd_data->stash, BUFFER_SIZE);
		fd_data->stash[readval] = 0;
		temp = ft_strjoin(temp, fd_data->stash);
	}
	return (tempsplit(temp, fd_data->stash));
}
