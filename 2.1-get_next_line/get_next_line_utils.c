/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/03 18:49:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;

	if (!s1)
		return (0);
	len = ft_strlen((char *)s1) + 1;
	dest = malloc(len * sizeof(char));
	if (!dest)
		return (0);
	len = 0;
	while (s1[len])
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = 0;
	return (dest);
}

char	*ft_strjoin(char *oldtemp, char *stash)
{
	char	*newtemp;
	int		i;
	int		oldlen;

	if (oldtemp == NULL || stash == NULL)
        return (NULL);
	newtemp = (char *)malloc(ft_strlen(oldtemp) + ft_strlen(stash) + 1);
	if (!newtemp)
		return (NULL);
	i = 0;
	oldlen = ft_strlen(oldtemp);
	ft_strncpy(newtemp, oldtemp, oldlen);
	while (stash[i]) //pb ici : Invalid read of size 1 quand entre avec null
		newtemp[oldlen++] = stash[i++];
	newtemp[oldlen] = 0;
	free(oldtemp);
	return (newtemp);
}

int	hasnewline(char *temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (*src != 0 && (int)len > 0)
	{
		*dst = *src;
		src++;
		dst++;
		len--;
	}
	*dst = 0;
	return (ptr);
}