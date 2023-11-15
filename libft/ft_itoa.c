/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:10:08 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/15 16:18:48 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

static void	revert_int_tab(char *s)
{
	int	start;
	int	end;
	char temp;

	start = 0;
	end = ft_strlen(s);
	if (s[start] == '-')
		start++;
	while (start < end / 2)
	{
		temp = s[start];
		s[start++] = s[end]; // cette boucle n'enregistre pas correctement
		s[end--] = temp;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(intlen(n));
	if (n < 0)
	{
		res[i++] = '-';
		n = -n;
	}
	while (n > 0)
	{
		res[i++] = (n % 10) + 48;
		n /= 10;
	}
	revert_int_tab(res);
	res[i] = 0;
	return (res);
}

#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-123));
//	char tab[] = "-3210";
//	revert_int_tab(tab);
//	printf("%s\n", tab);
}