/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:43:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/23 17:25:42 by mbecker          ###   ########.fr       */
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

char	*ft_to_base(long long nbr, char *base, short int baselen)
{
	short int	i;
	char		*res;

	if (!is_valid_base(base))
		return (NULL);
	res = (char *)malloc(ft_numlen_base(nbr, baselen));
	if (!res)
		return (NULL);
	i = 0;
	if (nbr == 0)
		res[i++] = base[nbr % baselen];
	if (nbr < 0)
	{
		res[i++] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		res[i++] = base[nbr % baselen];
		nbr /= baselen;
	}
	res[i] = 0;
	ft_revert_inttab(res);
	return (res);
}
