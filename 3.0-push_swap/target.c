/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:06:45 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/25 16:21:36 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @returns the closest smallest number of the stack ptr, or biggest if none
 * found.
 * @param node the node to find the target for.
 * @param ptr the stack to search in.
 */
t_list	*target_desc(t_list *node, t_list *ptr, t_list *targ, t_list *max)
{
	while (ptr)
	{
		if (targ == NULL && *node->content > *ptr->content)
			targ = ptr;
		if (targ && *node->content > *ptr->content
			&& *targ->content < *ptr->content)
			targ = ptr;
		if (*max->content < *ptr->content)
			max = ptr;
		ptr = ptr->next;
	}
	if (!targ)
		targ = max;
	return (targ);
}

/**
 * @returns the closest biggest number of the stack ptr, or smallest if none
 * found.
 * @param node the node to find the target for.
 * @param ptr the stack to search in.
 */
t_list	*target_asc(t_list *node, t_list *ptr, t_list *targ, t_list *min)
{
	while (ptr)
	{
		if (targ == NULL && *node->content < *ptr->content)
			targ = ptr;
		if (targ && *node->content < *ptr->content
			&& *targ->content > *ptr->content)
			targ = ptr;
		if (*min->content > *ptr->content)
			min = ptr;
		ptr = ptr->next;
	}
	if (!targ)
		targ = min;
	return (targ);
}

/**
 * @brief sets the target of each node of to_set to src.
 * @param to_set the stack of nodes to set the target for.
 * @param src the stack to search in.
 * @param ascending 1/TRUE for closest biggest, 0/FALSE for closest smallest.
 */
void	ft_settarget(t_list *to_set, t_list *src, int ascending)
{
	t_list	*target;
	t_list	*edge;

	if (!src || !src->next)
		return ;
	while (to_set)
	{
		target = NULL;
		edge = src;
		if (ascending)
			target = target_asc(to_set, src, target, edge);
		else
			target = target_desc(to_set, src, target, edge);
		to_set->target = target;
		to_set = to_set->next;
	}
}

void	ft_cleartarget(t_list *stack)
{
	while (stack)
	{
		stack->target = NULL;
		stack = stack->next;
	}
}
