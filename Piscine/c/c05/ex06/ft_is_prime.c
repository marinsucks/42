/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:23:11 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/10 21:23:13 by mbecker          ###   ########.fr       */
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

/*#include <stdio.h>

int	main(void)
{
	for (int i = 0; i < 100; i++)
	{
		if(ft_is_prime(i))
			printf("%i, ", i);
	}
	printf("%d\n", ft_is_prime(__INT_MAX__));
	return (0);
}

ALTERNATIVE

int	ft_is_prime(int nb)
{
	long int i;

	i = 3;
	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}*/