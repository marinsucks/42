/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:41:31 by mbecker           #+#    #+#             */
/*   Updated: 2023/07/12 19:41:33 by mbecker          ###   ########.fr       */
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

int	ft_ultimate_range(int **range, int min, int max)
{
	int	length;

	length = max - min;
	if (min >= max)
		return (0);
	*range = ft_range(min, max);
	if (range == 0)
		return (-1);
	return (length);
}

/*#include <stdio.h>

int	main(void)
{
	int     min = 20;
	int     max = 30;
	int     i = 0;
	int     *tab = ft_range(min, max);
	int     **range = &tab;
	if (!tab)
			return (0);
	while (i < (max - min))
	{
		printf("tab[%d] = %d \n",i, tab[i]);
		i++;
	}
	free(tab);

	min = 10;
	max = 20;
	printf("\nNEW TAB :\n");
	ft_ultimate_range(range, min, max);
	if (!tab)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		printf("tab[%d] = %d \n", i, tab[i]);
		i++;
	}
	printf("ultimate range return val : %d", ft_ultimate_range(range, min, max));
	free(tab);
}*/