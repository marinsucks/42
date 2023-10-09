/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:59:54 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/09 18:59:56 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	i = nb - 1;
	while (i > 1)
	{
		nb = nb * (i);
		i--;
	}
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	int nb = -5;
	printf("%d", ft_iterative_factorial(nb));
	return (0);
}*/