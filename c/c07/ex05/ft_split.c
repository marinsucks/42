/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:04:47 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/16 23:04:48 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *src, int size)
{
	char	*ptr;
	int		i;

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

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	wordcount(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (is_in_charset(str[i], charset) == 0 
			&& ((is_in_charset(str[i + 1], charset) == 1) || (str[i + 1] == '\0')))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	res = (char **)malloc(wordcount(str, charset) * sizeof(char *));
	if (!res)
		return (0);
	while (j < wordcount(str, charset))
	{
		size = 0;
		while (str[i] && is_in_charset(str[i], charset))
			i++;
		while (str[i] && is_in_charset(str[i], charset) == 0)
		{
			size++;
			i++;
		}
		res[j] = ft_strndup((str + i - size), size);
		j++;
	}
	res[j] = 0;
	return (res);
}

#include <stdio.h>
int main(int ac, char **av)
{
    (void) ac;

    char **tab;
    int    i;
    int    number;

    tab =ft_split(av[1], av[2]);
    i = 0;
    number = wordcount(av[1], av[2]);
    while (i < number)
    {
        printf("*%s*\n", tab[i]);
		if (tab[i] == 0)
			printf("void");
        i++;
    }
    printf("\n---\n\n");
}