/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:10:50 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

//returns the number of words in str, separated by char sep.
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

//returns the number of words in str, separated by any char of charset .
size_t	ft_wordcount_cset(const char *str, char *charset)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i])
			&& (ft_strchr(charset, str[i + 1]) || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}
