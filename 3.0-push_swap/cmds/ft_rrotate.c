/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:16:19 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/25 12:13:34 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstrrotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	else if ((*stack)->next->next == NULL)
	{
		ft_lstadd_front(stack, (*stack)->next);
		(*stack)->next->next = NULL;
		return ;
	}
	last = ft_lstlast(*stack);
	second_last = (*stack)->next;
	while (second_last->next != last)
		second_last = second_last->next;
	ft_lstadd_front(stack, last);
	second_last->next = NULL;
}

void	rra(t_list **stack_a)
{
	ft_lstrrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	ft_lstrrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_lstrrotate(stack_a);
	ft_lstrrotate(stack_b);
	write(1, "rrr\n", 4);
}
