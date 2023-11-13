/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:16 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/13 18:13:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	space_left;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	space_left = 0;
	if (size > dest_len)
		space_left = size - dest_len - 1;
	while (i < space_left && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0; //!!!
	if (dest_len < size)
		dest[dest_len + space_left] = 0;
	return (dest_len + src_len);
}

/*#include <stdio.h>

int	main()
{
	char *dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	int x = ft_strlcat(dest, "lorem", 15);


	printf("%d\n", x);
	for (int i = 0; i < 15; i++)
	{
		printf("%c", dest[i]);
		if (!isprint(dest[i]))
		{
			printf("%d", dest[i]);
		}
	}

	dest[0] = '\0';
	dest[11] = 'a';
	ft_strlcat(dest, "lorem ipsum", 15);
	printf("\n\n%d\n", x);
	for (int i = 0; i < 15; i++)
	{
		printf("%c", dest[i]);
		if (!isprint(dest[i]))
		{
			printf("%d", dest[i]);
		}
	}
}*/

/*size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	space_left;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;

	// Find the length of the destination string
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;

	// Find the length of the source string
	while (src[src_len] != '\0')
		src_len++;

	// Calculate the space available in the destination buffer
	space_left = 0;
	if (size > dest_len)
		space_left = size - dest_len - 1;

	// Copy the source string to the destination buffer
	while (i < space_left && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	// Null-terminate the destination buffer
	if (dest_len < size)
		dest[dest_len + space_left] = '\0';

	// Return the total length of the concatenated string
	return (dest_len + src_len);
}*/