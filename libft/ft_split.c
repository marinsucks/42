/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:10:50 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/15 15:18:15 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (src[i] && i < size)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	res = (char **)malloc(wordcount(s, c) * sizeof(char *));
	if (!res)
		return (0);
	while (j < wordcount(s, c) - 1)
	{
		size = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			size++;
			i++;
		}
		res[j] = ft_strndup((s + i - size), size);
		j++;
	}
	res[j] = NULL;
	return (res);
}
