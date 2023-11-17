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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	taille;

	taille = 0;
	while (str[taille])
	{
		taille++;
	}
	return (taille);
}

int	ft_error(char *str)
{
	int	base_len;
	int	i;
	int	j;

	base_len = ft_strlen(str);
	i = 0;
	if (base_len < 2)
		return (0);
	while (str[i])
	{
		j = i + 1;
		while (j < base_len)
		{
			if ((str[i] == str[j]) || (str[i] == '+' || str[i] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	limit_minus(long int nb, char *base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= ft_strlen(base))
	{
		limit_minus(nb / ft_strlen(base), base);
		limit_minus(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (ft_error(base) == 0)
		return ;
	if (nbr >= 0 && nbr < base_len)
	{
		ft_putchar(base[nbr]);
	}
	else if (nbr == -2147483648)
	{
		limit_minus(nbr, base);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(nbr * -1, base);
	}
	else
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
	}
}

int main()
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
}
