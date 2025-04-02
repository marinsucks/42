/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:10:08 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/23 13:50:24 by mbecker          ###   ########.fr       */
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
	ft_revert_inttab(res);
	return (res);
}
