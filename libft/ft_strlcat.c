/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:16 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:38:19 by mbecker          ###   ########.fr       */
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
	if (dest_len < size)
		dest[dest_len + space_left] = '\0';
	return (dest_len + src_len);
}

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