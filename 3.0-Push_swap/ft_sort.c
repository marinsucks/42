/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:58:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 15:37:42 by mbecker          ###   ########.fr       */
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
		{//delete me
			//ft_printf("Not sorted\n"); //delete me
			return (0);
		}//delete me
		i = ptr->content;
		ptr = ptr->next;
	}
	//ft_printf("Sorted\n"); //delete me
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

//void	ft_sort(t_list **stack_a, t_list **stack_b)
//{
//	int a_size;

//	a_size = ft_lstsize(*stack_a);
//	if (!ft_is_sorted(*stack_a))
//	{
		
//		if (a_size == 2)
//			sa(stack_a);
//		else if (a_size == 3)
//			ft_bubblesort(stack_a);
//		else
//			ft_turksort(stack_a, stack_b);
//	}
//}
