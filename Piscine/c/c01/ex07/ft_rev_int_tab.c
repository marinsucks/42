/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:25:32 by mbecker           #+#    #+#             */
/*   Updated: 2023/06/30 14:47:16 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	float	limit;

	i = 0;
	limit = size / 2;
	while (i < limit)
	{
		swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}

/* int main()
{
    int array[] = {1, 2, 3, 4, 5};
	int size = 5;

	ft_rev_int_tab(array, size);
	
	int i = 0;
	while (i < size)
	{
		printf("%d", array[i]);
		i++;
	}
	
    return 0;
} */