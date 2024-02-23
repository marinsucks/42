/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:40:26 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char	*ft_strtolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower((int)str[i]);
		i++;
	}
	return (str);
}

char	*ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper((int)str[i]);
		i++;
	}
	return (str);
}
