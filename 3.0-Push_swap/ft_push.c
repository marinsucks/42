/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:39:52 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/15 17:29:48 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// moves first node of src to the beginning of dst
void	ft_lstpush(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	ft_lstadd_front(dst, *src);
	*src = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_lstpush(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	ft_lstpush(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pa_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;

	ptr = *stack_b;
	while (ptr && *(int *)ptr->content > *(int *)ptr->next->content)
	{
		pa(stack_a, stack_b);
		ptr = (*stack_b)->next;
	}
}

void	pb_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		unsorted;

	ptr = *stack_a;
	unsorted = ft_find_unsorted(*stack_a) + 1;
	while (unsorted--)
	{
		pb(stack_a, stack_b);
		printBoth(stack_a, stack_b);
	}
}
