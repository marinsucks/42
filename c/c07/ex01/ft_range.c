/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:22:28 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/12 17:22:31 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	length;

	i = 0;
	length = max - min;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc((length + 1) * sizeof(int));
	if (!tab)
		return (NULL);
	while (i < length)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

/*#include <stdio.h>

int	main(void)
{
	int *tab = ft_range(-5, 5);

	for (int i = 0; i < 11; i++)
	{
		printf("%i", tab[i]);
	}
	return (0);
}*/
