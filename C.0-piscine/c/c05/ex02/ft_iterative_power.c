/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:43:51 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/10 15:44:11 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	i = 1;
	j = nb;
	if (power == 0)
		return (1);
	else if (nb == 0 || power < 0)
		return (0);
	while (i < power)
	{
		nb = nb * j;
		i++;
	}
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	int nb1 = 5;
	int nb2 = 0;
	int nb3 = -5;
	int power = -1;

	printf(" %i puissance %i est %i\n", nb1, power, ft_iterative_power(nb1,
			power));
	printf(" %i puissance %i est %i\n", nb2, power, ft_iterative_power(nb2,
			power));
	printf("%i puissance %i est %i\n", nb3, power, ft_iterative_power(nb3,
			power));
	return (0);
}*/
