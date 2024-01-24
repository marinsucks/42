/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optirotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:50:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/24 14:58:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief does the best rotate direction to get node and target to top of stack.
 * @param stack the stack to rotate.
 * @param node the node to rotate to the top of stack.
 * @param ab 'a' or 'b' to indicate which stack to rotate.
 */
void	ft_optirotate_one(t_list **stack, t_list *node, char ab)
{
	t_list	*tmp;
	int		median;

	tmp = node;
	median = ft_lstsize(*stack) / 2;
	while (median-- && tmp)
		tmp = tmp->next;
	if (tmp)
	{
		while (*stack != node && ab == 'a')
			ra(stack);
		while (*stack != node && ab == 'b')
			rb(stack);
	}
	else
	{
		while (*stack != node && ab == 'a')
			rra(stack);
		while (*stack != node && ab == 'b')
			rrb(stack);
	}
}

/**
 * @brief does the best rotate direction to get node and target to top of stack.
 * @param srclst the stack containing node.
 * @param tgtlst the stack containing node->target.
 * @param node the node to rotate to the top of stack.
 * @param ab 'a' or 'b' to indicate which stack is node in.
 */
void	ft_optirotate(t_list **srclst, t_list **tgtlst, t_list *node, char ab)
{
	t_list	*target;
	int		nodecost;
	int		tgetcost;

	target = node->target;
	nodecost = single_pushcost(srclst, node);
	tgetcost = single_pushcost(tgtlst, target);
	if (nodecost > 0 && tgetcost > 0)
	{
		while (nodecost-- > 0 && tgetcost-- > 0)
			rr(srclst, tgtlst);
	}
	else if (nodecost < 0 && tgetcost < 0)
	{
		while (nodecost++ < 0 && tgetcost++ < 0)
			rrr(srclst, tgtlst);
	}
	ft_optirotate_one(srclst, node, ab);
	ft_optirotate_one(tgtlst, target, ab);
	
}
