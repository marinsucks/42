/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/24 16:13:07 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_threesort(t_list **stack_a)
{
	t_list	*max;
	t_list	*ptr;

	max = *stack_a;
	ptr = *stack_a;
	while (ptr)
	{
		if (max && *max->content < *ptr->content)
			max = ptr;
		ptr = ptr->next;
	}
	if (max == *stack_a)
		ra(stack_a);
	else if (max == (*stack_a)->next)
		rra(stack_a);
	if (*(*stack_a)->content > *(*stack_a)->next->content)
		sa(stack_a);
}

/**
 * @see {@link https://medium.com/@ayogun/push-swap-c1f5d2d41e97} for 
 * detailed explanation
 */
void	ft_turksort(t_list **stack_a, t_list **stack_b)
{
	t_list	*topush;

	topush = NULL;
	while (ft_lstsize(*stack_a) > 3)
	{
		while (ft_lstsize(*stack_b) < 2 && ft_lstsize(*stack_a) > 3)
			pb(stack_a, stack_b);
		
		//printBoth(stack_a, stack_b); //delete me
		
		ft_settarget(*stack_a, *stack_b, FALSE);
		topush = ft_topush(stack_a, stack_b);
		ft_optirotate(stack_a, stack_b, topush, 'a');
		if (ft_lstsize(*stack_a) > 3)
			pb(stack_a, stack_b);
	}

	//printBoth(stack_a, stack_b); //delete me

	ft_threesort(stack_a);
	ft_cleartarget(*stack_a);
	while (*stack_b)
	{
		
		//printBoth(stack_a, stack_b); //delete me

		ft_settarget(*stack_b, *stack_a, TRUE);
		topush = ft_topush(stack_b, stack_a);
		ft_optirotate(stack_b, stack_a, topush, 'b');
		pa(stack_a, stack_b);
	}
	topush = ft_getmin(*stack_a);
	ft_optirotate_one(stack_a, topush, 'a');
}
