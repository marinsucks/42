/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:31 by mbecker           #+#    #+#             */
/*   Updated: 2024/05/14 16:14:24 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_tablen(const char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/**
 * returns the length of a number.
 */
short int	ft_numlen(long long num)
{
	short int			len;

	if (num < -9223372036854775807)
		return (20);
	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 10)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * returns the length of a number in a given base.
 * doesn't work with negative numbers - add 1 for the sign.
 */
short int	ft_numlen_base(unsigned long num, unsigned int baselen)
{
	short int			len;

	len = 1;
	while (num >= baselen)
	{
		len++;
		num /= baselen;
	}
	return (len);
}
