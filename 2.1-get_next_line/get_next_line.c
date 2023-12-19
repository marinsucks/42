/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:13 by mbecker           #+#    #+#             */
/*   Updated: 2023/12/19 15:11:29 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*makeres(char *temp)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (temp[len] != '\n' && temp[len])
		len++;
	len++;
	res = (char *)malloc(len + 1);
	while (i < len)
	{
		res[i] = temp[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

void	makestash(char *temp, char *stash)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	i++;
	while (temp[i])
		stash[j++] = temp[i++];
	stash[j] = 0;
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*res;
	char		*temp;
	int			readval;

	temp = ft_strdup(stash);
	stash[0] = 0;
	readval = read(fd, stash, BUFFER_SIZE); 
	if (readval <= 0)
		return (NULL);
	while (!hasnewline(temp) && readval > 0)
	{
		stash[0] = 0;
		readval = read(fd, stash, BUFFER_SIZE);
		temp = ft_strjoin(temp, stash);
	}
	res = makeres(temp);
	makestash(temp, stash); 
	free(temp);

	return (res);
}
