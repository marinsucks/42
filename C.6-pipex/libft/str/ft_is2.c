/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:33:35 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/20 19:46:46 by mbecker          ###   ########.fr       */
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
