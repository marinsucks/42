/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:23:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/24 14:49:10 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** 
 * @brief Calculates the cost of pushing a node to the top of a stack.
 * @returns the number of commands necessary to do so. A positive return 
 * value means ra, else rra.
 */
int	single_pushcost(t_list **list, t_list *node)
{
	int	cost;
	int	median;
	int	nodei;

	median = ft_lstsize(*list) / 2;
	nodei = ft_lstindex(list, node);
	if (nodei <= median)
		cost = nodei;
	else
		cost = nodei - ft_lstsize(*list);
	return (cost);
}

/** 
 * @brief Calculates the cost of pushing a node and its target to 
 * the top of a stack.
 * @param node the node to push.
 * @param srclist the stack containing node.
 * @param tgetlist the stack containing node->target.
 * @returns the least number of commands to do so
 */
int	global_pushcost(t_list **srclist, t_list **tgetlist, t_list *node)
{
	int	nodecost;
	int	tgetcost;
	int	totalcost;

	nodecost = single_pushcost(srclist, node);
	tgetcost = single_pushcost(tgetlist, node->target);
	totalcost = 0;
	if (nodecost >= 0 && tgetcost < 0)
		return (nodecost - tgetcost);
	else if (tgetcost >= 0 && nodecost < 0)
		return (tgetcost - nodecost);
	else if (nodecost < 0 && tgetcost < 0)
	{
		nodecost *= -1;
		tgetcost *= -1;
	}
	while (nodecost > 0 && tgetcost > 0)
	{
		nodecost--;
		tgetcost--;
		totalcost++;
	}
	totalcost += nodecost + tgetcost;
	return (totalcost);
}

/** 
 * @brief Analyses stacks and returns the cheapest node to push.
 * @note make sure to assign targets to all srclist nodes.
 * @param srclist the stack containing the node.
 * @param tgetlist the stack containing the targets.
 */
t_list	*ft_topush(t_list **srclist, t_list **tgetlist)
{
	t_list	*ptr;
	t_list	*res;
	int		mincost;

	ptr = *srclist;
	res = ptr;
	mincost = global_pushcost(srclist, tgetlist, ptr);
	if (mincost == 0)
		return (ptr);
	while (ptr)
	{
		if (mincost > global_pushcost(srclist, tgetlist, ptr))
		{
			mincost = global_pushcost(srclist, tgetlist, ptr);
			if (mincost == 0)
				return (ptr);
			res = ptr;
		}
		ptr = ptr->next;
	}
	return (res);
}
