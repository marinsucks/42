/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/03/25 11:58:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

// Check if c is one of the charset characters
int	ft_is(int c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (c);
		charset++;
	}
	return (0);
}

// Check if str is a number
int	ft_isnum(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
