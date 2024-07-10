/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:03:31 by mbecker           #+#    #+#             */
/*   Updated: 2023/06/30 11:52:35 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* int		main(void)
{
	int	x = 5;
	int	m;
	
	int	y = 25;
	int	n;
	
	ft_div_mod(x, y, &m, &n);
	printf("%i, %i // %i, %i\n", x, y, m, n);
	return (0);
} */
