/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:39:52 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/10 16:44:53 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstpush(t_list **stack_a, t_list **stack_b)
{
    t_list	*tmp;

    if (*stack_a == NULL || *stack_b == NULL)
        return ;
	//TODO
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_lstpush(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	ft_lstpush(stack_b, stack_a);
	write(1, "pb\n", 3);
}