/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:34:01 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/10 18:34:03 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*#include <stdio.h>

int main()
{
	for (int i = 0; i < 10; i++)
		printf("index = %i // result = %i\n", i, ft_fibonacci(i));

	printf("\n\nindex = -4 // result = %i\n", ft_fibonacci(-4));

	return (0);
}*/
