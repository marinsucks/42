/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:40:02 by mbecker           #+#    #+#             */
/*   Updated: 2023/10/30 16:40:04 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*str != 0)
	{
		if (*str == c)
			last_occ = str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return ((char *)last_occ);
}
