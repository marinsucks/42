/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:40:13 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:01 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

//returns a pointer to the first occurrence of the string needle in the string
//haystack, or NULL if the string needle is not found.
char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)(&haystack[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}

//returns a pointer to the first occurrence of the string needle in n bytes 
//of the string haystack, or NULL if the full string needle is not found.
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;
	int	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (!n)
		return (NULL);
	while (haystack[i] && n > 0)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && n > 0)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			n--;
		}
		i++;
		n += j;
		n--;
	}
	return (NULL);
}
