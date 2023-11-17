/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:16 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/17 15:06:52 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
