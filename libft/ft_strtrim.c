/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:25:45 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/14 19:03:57 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*res;

	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end - 1], set) && end != start)
		end--;
	res = (char *)malloc(end - start + 1);
	if (!res)
		return (NULL);
	while (start < end)
		res[i++] = s1[start++];
	res[i] = 0;
	return (res);
}
