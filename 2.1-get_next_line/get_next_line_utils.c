/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:38 by mbecker           #+#    #+#             */
/*   Updated: 2023/12/19 14:59:07 by mbecker          ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	temp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[i])
		temp[j++] = s1[i++];
	i = 0;
//	free(s1);
	while (s2[i])
		temp[j++] = s2[i++];
//	free(s2);
	temp[j] = 0;
	return (temp);
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
