/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:37:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:00 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptr;

	ptr = dst;
	while (*src != 0)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = 0;
	return (ptr);
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
