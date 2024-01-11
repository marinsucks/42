/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:10:50 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/11 12:38:17 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * splits a string into words, separated by a given char.
 * allocates and returns a NULL-terminated array of strings (words).
 */
char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	res = (char **)malloc(ft_wordcount(s, c) * sizeof(char *));
	if (!res)
		return (0);
	while (j < ft_wordcount(s, c) - 1)
	{
		start = 0;
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[j] = ft_strndup((s + start), i - start);
		j++;
	}
	res[j] = NULL;
	return (res);
}
