/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/16 14:05:20 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *stack)
{
	t_list	*ptr;
	int		*i;

	i = stack->content;
	ptr = stack->next;
	while (ptr)
	{
		if (*i > *(int *)ptr->content)
		{
			//ft_printf("Not sorted\n");
			return (0);
		}
		i = ptr->content;
		ptr = ptr->next;
	}
	//ft_printf("Sorted\n");
	return (1);
}

/** 
 * @brief returns index of first element that is not sorted, or max index if sorted.
 * @param ascending 1/TRUE for ascending, 0/FALSE for descending
 */
int	ft_find_unsorted(t_list *stack, int ascending)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = stack;
	if (ascending)
	{
		while (ptr->next && *(int *)ptr->content < *(int *)ptr->next->content)
		{
			i++;
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr->next && *(int *)ptr->content > *(int *)ptr->next->content)
		{
			i++;
			ptr = ptr->next;
		}
	}
	return (i);
}
