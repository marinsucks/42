/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/23 14:40:16 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_threesort(t_list **stack_a)
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

//void	ft_turksort(t_list **stack_a, t_list **stack_b)
//{
//	//pb until 3 elements left
//		//sort elements in b in descending order
//		// 1. pb 2 times in order to have a max and a min
//		while (ft_lstsize(*stack_b) < 2
//			pb(stack_a, stack_b);
//		// 2. find target node, which is the closest smaller number to current, or max value if none smaller
//		ft_settarget(*stack_b, *stack_b, FALSE);
//		// 3. cost analysis : find the cheapest node to push.
//		//	  pushcost(node) = x cmds for a on top + x cmds for a->target on top.
//		// 4. if pushcost(*stack_a) == 0 or is the cheapest, put *stack_a and its target on top of the lists and pb
//		//    -> do instructions for minimum pushcost. min pushcost by default is *stack_a's.

//	//sort 3 in a
//	//clear b target values

//	//pa until all elements are in a
//	//find target, which is the closest bigger number to current, or min value if none bigger.
//	//no cost analysis needed : b is sorted in descending order.

//	//best rotate for min.
//}
