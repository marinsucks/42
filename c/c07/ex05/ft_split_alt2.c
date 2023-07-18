/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:14:21 by mbecker          #+#    #+#              */
/*   Updated: 2023/07/17 14:14:24 by mbecker         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check(char c, char *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!(ft_check(str[i], charset)))
		{
			count++;
			while (str[i] && (!(ft_check(str[i], charset))))
				i++;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset, int *pos_str)
{
	int		first_pos;
	int		i;
	char	*ptr_dup;

	while (ft_check(str[*pos_str], charset))
			(*pos_str)++;
	first_pos = *pos_str;
	while (str[*pos_str] && !(ft_check(str[*pos_str], charset)))
		(*pos_str)++;
	ptr_dup = (char *)malloc(sizeof(char) * (*pos_str - first_pos + 1));
	if (!ptr_dup)
		return (NULL);
	i = 0;
	while ((first_pos + i) < (*pos_str))
	{
		ptr_dup[i] = str[first_pos + i];
		i++;
	}
	ptr_dup[i] = '\0';
	return (ptr_dup);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		pos;
	int		last;
	char	**tab;

	last = ft_count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * (last + 1));
	i = 0;
	pos = 0;
	if (!tab)
		return (NULL);
	tab[last] = 0;
	while (i < ft_count_words(str, charset))
	{
		tab[i] = ft_strdup(str, charset, &pos);
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>
int main(int ac, char **av)
{
	(void) ac;

	char **tab;
	int	i;
	int	number;

	tab =ft_split(av[1], av[2]);
	i = 0;
	number = ft_count_words(av[1], av[2]);
	while (i < number)
	{
		printf("||%s||\n", tab[i]);
		i++;
	}
	
}*/
