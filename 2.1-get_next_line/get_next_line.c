/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:13 by mbecker           #+#    #+#             */
/*   Updated: 2023/12/14 18:11:49 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*maketemp(char *stash, char *res)
{
	size_t	stashlen;
	size_t	reslen;
	char	*temp;
	int		i;

	stashlen = ft_strlen(stash);
	reslen = ft_strlen(res);
	temp = (char *)malloc(stashlen + reslen + 1);
	i = 0;
	while (i < stashlen)
	{
		temp[i] = stash[i];
		i++;
	}
	i = 0;
	while (i < reslen)
		temp[stashlen++] = res[i++];
	temp[stashlen] = 0;
	return (temp);
}

char	*makeres(char *temp)
{
	char	*res;
	int		len;

	len = 0;
	while (temp[len] != '\n')
		len++;
	len++;
	res = (char *)malloc(len + 1);
	while (len--)
		res[len] = temp[len];
	res[len] = 0;
	return (res);
}

char	*makestash(char *temp, char *oldstash)
{
	int		oldlen;
	int		start;
	char	*newstash;

	start = 0;
	while (temp[start] != '\n' && temp[start])
		start++;
	if (temp[start] == '\n') // A REVOIR
		start++;
	else
		start = 0;
	oldlen = ft_strlen(oldstash);
	printf("start: %d\n", start);
	printf("oldlen: %d\n", oldlen);
	newstash = (char *)malloc(ft_strlen(temp) - start + oldlen + 1); //+ oldlen
	start++;
	while (temp[oldlen])
	{
		newstash[oldlen] = temp[start];
		oldlen++;
		start++;
	}
	newstash[oldlen] = 0;
	return (newstash);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*res;
	char		*temp;
	int			readval;

	readval = read(fd, res, BUFFER_SIZE);
	if (readval == -1)
		return (NULL);
	while (readval > 0 || nonewline(temp)) // read until EOF
	{
		temp = maketemp(stash, res);
		res = makeres(temp);
		// new stash = stash\n.....[del]
		// free(stash);
		free(temp);
	}
	return (res);
}
