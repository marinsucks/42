/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 11:33:11 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubblesort(t_list **stack_a, t_list **stack_b)
{
	//t_list	*last;
	//-> optimisation :	si last < first, rotate
	// 					si first > *, rrotate.
	int i;
	size_t	len;

	len = ft_lstsize(*stack_a);
	i = 15;
	while (!ft_is_sorted(*stack_a) || *stack_b)
	{
		if (ft_lstindex(stack_a, *stack_a) )
		pb_sorted(stack_a, stack_b);
		sa(stack_a);
		printBoth(stack_a, stack_b);
		ft_printf("i = %d\n", i);
		if ((!*stack_a || !i--))
			pa_sorted(stack_a, stack_b);
	}
}