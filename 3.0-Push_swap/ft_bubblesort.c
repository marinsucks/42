/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 17:09:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubblesort(t_list **stack_a)
{
	int		first;
	int		second;
	int 	third;
	t_list	*ptr;

	int i = 0;
	while (!ft_is_sorted(*stack_a))
	{
		ptr = *stack_a;
		first = *(int *)ptr->content;
		second = *(int *)ptr->next->content;
		third = *(int *)ptr->next->next->content;
		if (first > second)
			sa(stack_a);
		if (second > first && second > third)
			rra(stack_a);
		if (i++ == 3)
			exit(1);
	}
}
