/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:43:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/23 15:44:48 by mbecker          ###   ########.fr       */
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

void	ft_putnbr_base(long long nbr, char *base)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (is_valid_base(base) != 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
		}
		if (nbr >= baselen)
			ft_putnbr_base(nbr / baselen, base);
		ft_putchar_fd(base[nbr % baselen], 1);
	}
}
