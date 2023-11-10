/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:11:16 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/10 17:11:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	niktamair;

	if (start > ft_strlen(s))
		return (NULL);
	
	res = (char *)malloc(len);
	if (!res)
		return (NULL);

	s += start;
	niktamair = ft_strlcpy(res, s, len);

	return res;
}