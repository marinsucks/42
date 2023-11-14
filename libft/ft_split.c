/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:10:50 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/14 19:48:37 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep 
			&& (str[i + 1] == sep || str[i + 1] == 0))
			count++;
		i++;
	}
	//printf("wordcount= \t%zu\n", count);
	return (count);
}

static char	*ft_strndup(const char *src, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	ptr = (char *)malloc((size + 1) * sizeof(char *));
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
	while (j < wordcount(s, c))
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
	res[j] = 0;
	return (res);
}

//#include <stdio.h>
//int main()
//{
//	char test[] = "testxdesxenfersxx";
//	char **res = ft_split(test, 'x');
//	for (size_t i = 0; res[i]; i++)
//		printf("%s\n", res[i]);
//}
