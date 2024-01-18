/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:16:19 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 15:47:10 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
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
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	ft_best_rotate(t_list **stack, t_list *node)
{
	int		median;

	median = ft_lstsize(*stack) / 2;
	while (median-- && node)
		node = node->next;
	if (node)
		write(1, "ra\n", 3);
	else
		write(1, "rra\n", 4);
	ft_printf("median: %d\n", median);
	ft_printf("node: %p\n", node);
}