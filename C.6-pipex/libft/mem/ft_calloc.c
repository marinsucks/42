/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:21:51 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:51 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/**
 * Allocates memory for an array of elements and initializes them to zero.
 *
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
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
