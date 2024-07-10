/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:56:08 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/10 11:56:11 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	else
		return (nb * (ft_recursive_factorial(nb - 1)));
}

/*#include <stdio.h>

int	main(void)
{
	int nb = 5;
	printf("%i\n", ft_recursive_factorial(nb));
	return (0);
}*/
