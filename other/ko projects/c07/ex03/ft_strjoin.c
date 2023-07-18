/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:23:41 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/13 12:23:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_length(int size, char **tab, char *sep)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	count = ((size - 1) * i) + count;
	return (count + 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_str_cpy_cat(char *src, char *sep, char *result, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		result[len + i] = src[i];
		i++;
	}
	while (sep[j])
	{
		result[len + i + j] = sep[j];
		j++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	char	len;

	i = 0;
	if (size <= 0)
	{
		result = (char *)malloc(sizeof(char));
		result = NULL;
		return (result);
	}
	result = (char *)malloc(ft_length(size, strs, sep) * sizeof(char));
	if (result == NULL)
		return (0);
	while (i < size)
	{
		len = ft_strlen(result);
		ft_str_cpy_cat(strs[i], sep, result, len);
		i++;
	}
	result[ft_strlen(result)] = '\0';
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	char *strs[] = {"ayoo", "cette", "piscine", "aura", "ma", "mort", "3ed",
		"/'[[]]", "x = 0 ;"};
	char sep[] = "---";

	printf("%s", ft_strjoin(9, strs, sep));

	return (0);
}*/