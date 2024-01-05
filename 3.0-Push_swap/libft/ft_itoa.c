/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:10:08 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/16 11:44:05 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long ln)
{
	int	len;

	len = 1;
	if (ln < 0)
	{
		len++;
		ln = -ln;
	}
	while (ln >= 10)
	{
		len++;
		ln /= 10;
	}
	return (len + 1);
}

static void	revtab(char *s)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(s) - 1;
	if (s[start] == '-')
		start++;
	while (start < end)
	{
		temp = s[start];
		s[start++] = s[end];
		s[end--] = temp;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	long	ln;
	int		i;

	i = 0;
	ln = n;
	res = (char *)malloc(intlen(ln));
	if (!res)
		return (NULL);
	if (ln == 0)
		res[i++] = '0';
	if (ln < 0)
	{
		res[i++] = '-';
		ln = -ln;
	}
	while (ln > 0)
	{
		res[i++] = (ln % 10) + 48;
		ln /= 10;
	}
	res[i] = 0;
	revtab(res);
	return (res);
}
