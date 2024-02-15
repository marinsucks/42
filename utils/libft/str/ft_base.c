/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:43:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:13:58 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*is_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str[0] || !str[1])
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j] && str[i] != str[j])
			j++;
		if (str[j] == str[i])
			return (0);
		i++;
	}
	return (str);
}

/**
 * Transforms an int into a string of the base given as parameter.
 *
 * @param nbr The int for which the base needs to be calculated.
 * @param base The base of the integer.
 * @param baselen The length of the base.
 */
char	*ft_intbase(unsigned int nbr, char *base, unsigned int baselen)
{
	short int	i;
	char		*res;

	i = 0;
	if (!is_valid_base(base))
		return (NULL);
	res = (char *)malloc(ft_numlen_base(nbr, baselen) + 1);
	if (!res)
		return (NULL);
	if (nbr == 0)
		res[i++] = base[nbr % baselen];
	while (nbr > 0)
	{
		res[i++] = base[nbr % baselen];
		nbr /= baselen;
	}
	res[i] = 0;
	ft_revert_inttab(res);
	return (res);
}

/**
 * transforms an ulong into a string of the base given as parameter.
 *
 * @param nbr The ulong for which the base needs to be calculated.
 * @param base The base of the integer.
 * @param baselen The length of the base.
 */
char	*ft_longbase(unsigned long nbr, char *base, unsigned int baselen)
{
	short int	i;
	char		*res;

	i = 0;
	if (!is_valid_base(base))
		return (NULL);
	res = (char *)malloc(ft_numlen_base(nbr, baselen) + 1);
	if (!res)
		return (NULL);
	if (nbr == 0)
		res[i++] = base[nbr % baselen];
	while (nbr > 0)
	{
		res[i++] = base[nbr % baselen];
		nbr /= baselen;
	}
	res[i] = 0;
	ft_revert_inttab(res);
	return (res);
}
