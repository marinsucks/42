/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/16 13:57:09 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion_sort(t_list **stack_a, t_list **stack_b)
{
	//t_list	*last;
	//-> optimisation :	si last < first, rotate
	// 					si first > *, rrotate.

	while (!ft_is_sorted(*stack_a) || *stack_b)
	{
		pb_sorted(stack_a, stack_b);
		sa(stack_a);
		if (ft_is_sorted(*stack_a))
		{
			pa_sorted(stack_a, stack_b);
			pa(stack_a, stack_b);
			break ;
		}
	}
}