/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:16:19 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/19 14:20:09 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstrotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	if (first == NULL)
		return ;
	second = (*stack)->next;
	if (second == NULL)
		return ;
	ft_lstadd_back(stack, first);
	first->next = NULL;
	*stack = second;
}

void	ra(t_list **stack_a)
{
	ft_lstrotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	ft_lstrotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_lstrotate(stack_a);
	ft_lstrotate(stack_b);
	write(1, "rr\n", 3);
}

//finds the best rotate direction to get node to top of stack and does it.
void	ft_best_rotate(t_list **stack, t_list *node)
{
	t_list	*tmp;
	int		median;

	tmp = node;
	median = ft_lstsize(*stack) / 2;
	while (median-- && tmp)
		tmp = tmp->next;
	if (tmp)
	{
		while (*stack != node)
			ra(stack);
	}
	else
	{
		while (*stack != node)
			rra(stack);
	}
}
