/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:55:07 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/10 19:55:08 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	j;

	i = 1;
	while (i <= 46340)
	{
		j = i * i;
		if (nb == j)
			return (i);
		else if (j > nb)
			return (0);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main()
{
	printf("nb = -81 \t\t result = %i\n", ft_sqrt(-81));
	printf("nb = 0 \t\t\t result = %i\n", ft_sqrt(0));
	printf("nb = 1 \t\t\t result = %i\n", ft_sqrt(1));
	printf("nb = 2147395600 \t result = %i\n", ft_sqrt(2147395600));
	printf("nb = 84 \t\t result = %i\n", ft_sqrt(84));
	printf("nb = 15129 \t\t result = %i\n", ft_sqrt(15129));

	return (0);
}*/