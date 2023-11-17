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
	if (str[0] == '\0' || charset[0] == '\0')
		return (0);
	while (str[i])
	{
		if (is_in_charset(str[i], charset) == 0 && ((is_in_charset(str[i + 1],
						charset) == 1) || (str[i + 1] == '\0')))
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

/*#include <unistd.h>
#include <stdio.h>

 void	puttab(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, " // ", 4);
		i++;
	}
	//write(1, "\n\n", 6);
}

 int	main(void)
{
	write(1, "test 1 = \"                 \", \"     \"", 37);
	write(1, "\n", 1);
	char **a = ft_split("                 ", "     ");
	puttab(a);
	write(1, "$\n$\n\n", 5);

	write(1, "test 2 = \"RYESPhn\", \"RYESPhn\"", 29);
	write(1, "\n", 1);
	char **b = ft_split("RYESPhn", "RYESPhn");
	puttab(b);
	write(1, "$\n$\n\n", 5);

	write(1, "test 3 = \"5rNPgnW\", \"5rNPgnW\"", 29);
	write(1, "\n", 1);
	char **c = ft_split("5rNPgnW", "5rNPgnW");
	puttab(c);
	write(1, "$\n$\n\n", 5);

	write(1, "test 4 = \"F kGQue1oMgH9QEQ2gXkJvim0SGteobtl\", \"178fD02\"", 55);
	write(1, "\n", 1);
	char **d = ft_split("F kGQue1oMgH9QEQ2gXkJvim0SGteobtl", "178fD02");
	puttab(d);
	write(1, "$\n$\n\n", 5);

	write(1, "test 5 = \"kH6wwYBHPyFiLRWwWOZEkah6FuSdLLsnj1zJVFAYDdkCd\",
		\"4p0MqnZ\"", 67);
	write(1, "\n", 1);
	char **e = ft_split("kH6wwYBHPyFiLRWwWOZEkah6FuSdLLsnj1zJVFAYDdkCd lj",
		"4p0MqnZ");
	puttab(e);
	write(1, "$\n$\n\n", 5);

	write(1, "test 6 = \"7wxEKluNVGx3twO1fUv2B5BJaO0U9v vO        244Dmj\",
		\"mZPH\"", 66);
	write(1, "\n", 1);
	char **f = ft_split("7wxEKluNVGx3twO1fUv2B5BJaO0U9v vO        244Dmj",
		"mZPH");
	puttab(f);
	write(1, "$\n$\n\n", 5);

	write(1, "test 7 = \"GGOTx3XzNNruSHqsvjzjEuJID abf64Fx2QWr3TXiB\",
		\"KL0mR\"", 62);
	write(1, "\n", 1);
	char **g = ft_split("GGOTx3XzNNruSHqsvjzjEuJID abf64Fx2QWr3TXiB", "KL0mR");
	puttab(g);
	write(1, "$\n$\n\n", 5);

	write(1, "test 8 = \"k64Wui0uxfhxhfA0lB4tmNCQJkHsjui\", \"gx36\"", 50);
	write(1, "\n", 1);
	char **h = ft_split("k64Wui0uxfhxhfA0lB4tmNCQJkHsjui", "gx36");
	puttab(h);
	write(1, "$\n$\n\n", 5);

	write(1,
		"test 9 = \"G0SBU35o9ymWZUEs4prXq9CWCtUnird3BG       9AYdlIicAVHrom\",
			\"RYESPhn\"", 77);
	write(1, "\n", 1);
	char **i = ft_split("G0SBU35o9ymWZUEs4prXq9CWCtUnird3BG       9AYdlIicAVHrom",
		"02Vxy4");
	puttab(i);
	write(1, "$\n$\n\n", 5);

	write(1, "test 10 = \"  gh  \", \" gh\"", 25);
	write(1, "\n", 1);
	char **j = ft_split("  gh  ", " gh");
	puttab(j);
	write(1, "$\n$\n\n", 5);

	write(1, "test 11 = \"  gh  \", \" \"", 23);
	write(1, "\n", 1);
	char **k = ft_split("  gh  ", " ");
	puttab(k);
	write(1, "$\n$\n\n", 5);

	write(1, "test 12 = \" L4wb 1JD9KWNVmutjkqP8BvCg2zzF\", \"\"", 46);
	write(1, "\n", 1);
	char **l = ft_split(" L4wb 1JD9KWNVmutjkqP8BvCg2zzF", "");
	puttab(l);
	write(1, "$\n$\n\n", 5);

	return (0);
}*/
