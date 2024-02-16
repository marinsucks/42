/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:40:37 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:01 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/**
 * Searches for the first occurrence of any character from the set 
 * in the given string.
 *
 * @param s The string to search in.
 * @param set The set of characters to search for.
 * @return The ASCII value of the first character found in the set,
 *  or 0 if no match is found.
 */
int	ft_strset(char *s, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j++])
				return (set[j - 1]);
		}
		i++;
	}
	return (0);
}
