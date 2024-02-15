/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:11:16 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_sublen(char const *s, unsigned int start, size_t len)
{
	size_t	slen;

	slen = ft_strlen(s) + 1;
	if (start > slen)
		return (1);
	else if (len > (slen - start))
		return (slen - start);
	else
		return (len + 1);
}

/**
 * allocates (with malloc(3)) and returns a substring from the string ’s’.
 * @param start the start index of the substring in the string ’s’.
 * @param len the maximum length of the substring.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_sublen(s, start, len);
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	while (start < ft_strlen(s) && s[start] && --size)
		res[i++] = s[start++];
	res[i] = 0;
	return (res);
}
