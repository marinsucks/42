/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:37:31 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/10 16:37:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (nb == 0 || power < 0)
		return (0);
	return (nb * (ft_recursive_power(nb, power - 1)));
}

/*#include <stdio.h>

int main()
{
	int nb1 = 5;
	int nb2 = 0;
	int nb3 = -5;
	int power = -1;

	printf(" %i puissance %i est %i\n", nb1, power, ft_recursive_power(nb1, power));
	printf(" %i puissance %i est %i\n", nb2, power, ft_recursive_power(nb2, power));
	printf("%i puissance %i est %i\n", nb3, power, ft_recursive_power(nb3, power));
	return 0;
}*/