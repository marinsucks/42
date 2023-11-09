/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:34:58 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:34:59 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
