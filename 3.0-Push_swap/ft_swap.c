/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:08:49 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/16 12:53:49 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap(t_list **node)
{
	t_list	*tmp;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	tmp = (*node)->next;
	(*node)->next = tmp->next;
	tmp->next = *node;
	*node = tmp;
}

void	sa(t_list **stack_a)
{
	ft_lstswap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	ft_lstswap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_lstswap(stack_a);
	ft_lstswap(stack_b);
	write(1, "ss\n", 3);
}
