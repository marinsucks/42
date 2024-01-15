/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/15 17:29:38 by mbecker          ###   ########.fr       */
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
			ft_printf("KO\n");
			return (0);
		}
		i = ptr->content;
		ptr = ptr->next;
	}
	ft_printf("OK\n");
	return (1);
}

// returns index of first element that is not sorted, or max index if sorted.
int	ft_find_unsorted(t_list *stack)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = stack;
	while (ptr->next && *(int *)ptr->content < *(int *)ptr->next->content)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	ft_insertion_sort(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (!ft_is_sorted(stack_a) && stack_b)
	{
		pb_sorted(&stack_a, &stack_b);
	}
}
