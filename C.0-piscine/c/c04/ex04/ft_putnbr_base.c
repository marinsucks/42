/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:43:46 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/06 17:43:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr, int base_l, char *base)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= base_l)
		ft_putnbr(nbr / base_l, base_l, base);
	ft_putchar(base[nbr % base_l]);
}

char	*ft_basecmp(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == 0 || str[1] == 0)
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (str[j] && str[i] != str[j])
			j++;
		if (str[j] == str[i] || str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (str);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_l;

	base_l = ft_strlen(base);
	if (ft_basecmp(base) != 0)
	{
		if (nbr == -2147483648)
		{
			ft_putnbr(nbr / base_l, base_l, base);
			ft_putnbr(nbr % base_l * -1, base_l, base);
		}
		else
			ft_putnbr(nbr, base_l, base);
	}
}

/*int main()
{
	char dec[] = "0123456789";
	char hex[] = "0123456789ABCDEF";
	char oct[] = "marinsqx";
	char bin[] = "01";

	int nb = 42;
	ft_putnbr_base(nb, hex);
	write(1, "\n", 1);
	ft_putnbr_base(nb, dec);
	write(1, "\n", 1);
	ft_putnbr_base(nb, oct);
	write(1, "\n", 1);
	ft_putnbr_base(nb, bin);
	write(1, "\n", 1);
	return (0);
}*/