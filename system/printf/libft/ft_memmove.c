/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:35:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
