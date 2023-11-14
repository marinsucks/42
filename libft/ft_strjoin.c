/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:40:08 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/14 15:14:15 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc(l1 + l2 + 1);
	while (*s1)
	{
		*res = *s1;
		s1++;
		res++;
	}
	while (*s2)
	{
		*res = *s2;
		s2++;
		res++;
	}
	*res = 0;
	return (res - l1 - l2);
}
