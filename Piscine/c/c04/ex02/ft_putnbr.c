/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:22:47 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/05 19:22:49 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb != -2147483648)
	{
		if (nb >= 0 && nb <= 9)
		{
			write_char(nb + '0');
		}
		else if (nb < 0)
		{
			write_char('-');
			ft_putnbr(-nb);
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
	else
		write(1, "-2147483648", 11);
}

/*int	main()
{
	ft_putnbr(-2147483648);
	ft_putnbr(0);
	ft_putnbr(-135);
	ft_putnbr(135);
}*/
