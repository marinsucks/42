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
		write(1, "strdup malloc fail", 19);
	len = 0;
	while (s1[len])
	{
		dest[len] = s1[len];
		len++;
	}
	dest[len] = 0;
	return (dest);
}

/* #include <stdio.h>

int	main(int argc, char *argv[])
{
	int i = argc;
	i++;
	char *strdup_src = argv[1];
	char *strdup_dst = ft_strdup(strdup_src);
	printf("STRDUP\n");
	printf("src = %s\n", strdup_src);
	printf("dst output = %s\n", strdup_dst);
	free(strdup_dst);
	return (0);
} */
