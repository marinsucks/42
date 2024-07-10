/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:16:12 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/15 10:16:16 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' 
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	spaces_sign_check(int i, int *sign, char *str)
{
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	btoi(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	baselen;

	i = 0;
	sign = 1;
	res = 0;
	baselen = ft_strlen(base);
	if (ft_check_base(base) == 0)
		return (0);
	i = spaces_sign_check(i, &sign, str);
	while (btoi(str[i], base) >= 0)
	{
		res = res * baselen + btoi(str[i], base);
		i++;
	}
	return (sign * res);
}

/*#include <stdio.h>

int	main(void)
{
	char bin[] = "01";
	char oct[] = "marinxyz";
	char dec[] = "0123456789";
	char hex[] = "0123456789ABCDEF";

	char test1[] = "   --101010xxx";
	printf("%i\n", ft_atoi_base(test1, bin));
	char test2[] = "   --xr.xxx";
	printf("%i\n", ft_atoi_base(test2, oct));
	char test3[] = "   --42xxx";
	printf("%i\n", ft_atoi_base(test3, dec));
	char test4[] = "   --2Ax4";
	printf("%i\n", ft_atoi_base(test4, hex));

	return (0);
}*/
