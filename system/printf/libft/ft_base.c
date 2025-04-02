/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:43:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/27 17:00:46 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_valid_base(char *str)
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

char	*int_to_base(unsigned int nbr, char *base, unsigned int baselen)
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

char	*long_to_base(unsigned long nbr, char *base, unsigned int baselen)
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
