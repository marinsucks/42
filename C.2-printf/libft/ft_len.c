/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:38:31 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/27 15:45:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

short int	ft_numlen(long long num)
{
	short int			len;

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

short int	ft_numlen_base(unsigned long num, unsigned int baselen)
{
	short int			len;

	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= baselen)
	{
		len++;
		num /= baselen;
	}
	return (len);
}
