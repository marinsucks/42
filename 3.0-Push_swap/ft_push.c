/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:39:52 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 12:25:03 by mbecker          ###   ########.fr       */
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

//pushes all sorted elements of stack_b to stack_a
void	pa_sorted(t_list **stack_a, t_list **stack_b, int additional)
{
	t_list	*ptr;
	int		unsorted;

	ptr = *stack_b;
	unsorted = ft_find_unsorted(*stack_b, FALSE);
	while (unsorted--)
		pa(stack_a, stack_b);
	while (additional--)
		pa(stack_a, stack_b);
	//printBoth(stack_a, stack_b); //delete me
}

//pushes all sorted elements of stack_a to stack_b
void	pb_sorted(t_list **stack_a, t_list **stack_b, int additional)
{
	t_list	*ptr;
	int		unsorted;

	ptr = *stack_a;
	unsorted = ft_find_unsorted(*stack_a, TRUE);
	while (unsorted--)
		pb(stack_a, stack_b);
	while (additional--)
		pb(stack_a, stack_b);
	//printBoth(stack_a, stack_b); //delete me
}
