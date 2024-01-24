/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/24 15:09:37 by mbecker          ###   ########.fr       */
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

t_list	*ft_getmin(t_list *stack)
{
	t_list	*ptr;

	ptr = stack;
	while (ptr)
	{
		if (*stack->content > *ptr->content)
			stack = ptr;
		ptr = ptr->next;
	}
	return (stack);
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
