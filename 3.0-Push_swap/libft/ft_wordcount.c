/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:10:50 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/11 12:51:20 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//returns the number of words in str, separated by sep.
size_t	ft_wordcount(const char *str, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}
