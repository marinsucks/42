/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:35:34 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:35:37 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
 
	d = (char *)dst;
	s = (char *)src;
	while (n > 0 && src != NULL)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
} 

#include <stdio.h>
#include <string.h>

int main() {

    char buffer[] = "test goddamn";
	char *malloc = ft_strdup(buffer);
	memcpy(malloc + 4, malloc, 5);
    printf("%s\n", malloc);
	free(malloc);

	malloc = ft_strdup(buffer);
	ft_memcpy(malloc + 4, malloc, 5);
    printf("%s\n", malloc);
	free(malloc);

    return 0;
}
