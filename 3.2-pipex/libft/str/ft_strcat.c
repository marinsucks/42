/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:36:15 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:00 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptr;

	ptr = s1;
	while (*s1 != 0)
		s1++;
	while (*s2 != 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
	return (ptr);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;

	ptr = s1;
	while (*s1 != 0)
		s1++;
	while (*s2 != 0 && (int)n > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	*s1 = 0;
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if ((!dst || !src) && (size == 0))
		return ((size_t) NULL);
	j = ft_strlen((const char *)dst);
	if (j > size)
		return (size + ft_strlen(src));
	if (!src)
		return (j);
	if (!size)
		return (ft_strlen(src) + j);
	i = 0;
	while (src[i] && (i + j) < size - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (j + ft_strlen(src));
}
