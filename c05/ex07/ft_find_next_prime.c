/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:23:57 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/11 14:23:59 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (nb <= 1)
		return (2);
	while (i)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	printf("0 => %d\n", ft_find_next_prime(0));
	printf("-15 => %d\n", ft_find_next_prime(-15));
	printf("4576 => %d\n", ft_find_next_prime(4576));
	printf("2147483647 => %d\n", ft_find_next_prime(2147483647));
	return (0);
}*/