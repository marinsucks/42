/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:21:51 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/07 16:21:54 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	memsize;

	memsize = nmemb * size;
	if (size && memsize / size != nmemb)
		return (NULL);
	res = (char *)malloc(memsize);
	if (!res)
		return (NULL);
	ft_memset(res, 0, memsize);
	return (res);
}
