/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:34:58 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:52 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

//searches for the first occurrence of c in n bytes of s.
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sc;

	sc = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (*sc == (unsigned char)c)
			return ((unsigned char *)sc);
		sc++;
		n--;
	}
	if (c == 0)
		return ((unsigned char *)sc);
	else
		return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n > 0)
	{
		if ((unsigned char)*us1 != (unsigned char)*us2)
			return ((unsigned char)*us1 - (unsigned char)*us2);
		us1++;
		us2++;
		n--;
	}
	return (0);
}

/** 
 * copies n bytes from memory area src to memory area dst.
 * use memmove in case of overlapping memories.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	while (n > 0 && (src != NULL || dst != NULL))
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

//copies n bytes from memory area src to memory area dst.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (src < dst && src + len > dst)
	{
		d += len - 1;
		s += len - 1;
		while (len > 0)
		{
			*d = *s;
			d--;
			s--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;
	unsigned char	uc;

	ub = b;
	uc = c;
	while (len > 0)
	{
		*ub = uc;
		ub++;
		len--;
	}
	return (b);
}
