/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/23 15:51:04 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// @returns 1 if stack is sorted, else 0
int	ft_is_sorted(t_list *stack)
{
	t_list	*ptr;
	int		*i;

	i = stack->content;
	ptr = stack->next;
	while (ptr)
	{
		if (*i > *(int *)ptr->content)
			return (0);
		i = ptr->content;
		ptr = ptr->next;
	}
	return (1);
}

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

///** 
// * @returns index of first element that is not sorted, or max index if sorted.
// * @param ascending 1/TRUE for ascending, 0/FALSE for descending
// */
//int	ft_find_unsorted(t_list *stack, int ascending) //delete me
//{
//	int		i;
//	t_list	*ptr;

//	i = 0;
//	ptr = stack;
//	if (ascending)
//	{
//		while (ptr->next && *(int *)ptr->content < *(int *)ptr->next->content)
//		{
//			i++;
//			ptr = ptr->next;
//		}
//	}
//	else
//	{
//		while (ptr->next && *(int *)ptr->content > *(int *)ptr->next->content)
//		{
//			i++;
//			ptr = ptr->next;
//		}
//	}
//	return (i);
//}