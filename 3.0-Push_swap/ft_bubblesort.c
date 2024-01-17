/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/17 16:16:52 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubblesort(t_list **stack_a, t_list **stack_b)
{
	//t_list	*last;
	//-> optimisation :	si last < first, rotate
	// 					si first > *, rrotate.
	int i;

	i = 15;
	while (!ft_is_sorted(*stack_a) || *stack_b)
	{
		pb_sorted(stack_a, stack_b);
		sa(stack_a);
		pa_sorted(stack_a, stack_b);
		if ((ft_is_sorted(*stack_a) && !*stack_b) || !i--)
			break;
		//if (ft_is_sorted(*stack_a) && *stack_b)
		//{
		//	printBoth(stack_a, stack_b);
		//	pa_sorted(stack_a, stack_b);
		//	pa(stack_a, stack_b);
		//	break ;
		//}
	}
}