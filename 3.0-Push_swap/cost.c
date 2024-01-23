/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:23:38 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/23 17:25:05 by mbecker          ###   ########.fr       */
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
	int nodei;

	median = ft_lstsize(*list) / 2;
	nodei = ft_lstindex(list, node);
	//ft_printf("median = %d\n", median); //delete me
	//ft_printf("node index = %d\n", nodei); //delete me
	if (nodei <= median)// && ft_lstsize(*list) % 2 == 1)
		cost = nodei;
	//else if (nodei < median)
	//	cost = nodei;
	else
		cost = nodei - ft_lstsize(*list);
	//ft_printf("cost = %d\n\n", cost); //delete me
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
	ft_printf("nodecost = %d\n", nodecost); //delete me
	ft_printf("tgetcost = %d\n", tgetcost); //delete me
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
 * @param srclist the stack containing node.
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
	while (ptr)
	{
		ft_printf("\nNODE %d, TARGET %d\n", *(int *)ptr->content, *(int *)ptr->target->content); //delete me
		ft_printf("mincost = %d\n", mincost); //delete me
		ft_printf("global_pushcost = %d\n", global_pushcost(srclist, tgetlist, ptr)); //delete me
		if (mincost > global_pushcost(srclist, tgetlist, ptr))
		{
			mincost = global_pushcost(srclist, tgetlist, ptr);
			res = ptr;
		}
		ft_printf("res = %d\n", *res->content); //delete me
		ptr = ptr->next;
	}
	return (ptr);
}
