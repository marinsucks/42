/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:37:55 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:37:56 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;

	len = 0;
	while (s1[len])
		len++;
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
