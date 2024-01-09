/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:16:45 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/09 23:54:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//don't forget to free stack after use
t_list	*ft_makestack(int argc, char const *argv[])
{
	t_list	*stack;
	t_list	*new_node;
	int		*numptr;

	stack = NULL;
	while (argc > 1)
	{
		numptr = (int *)malloc(sizeof(int));
		*numptr = ft_atoi(argv[--argc]);
		new_node = ft_lstnew(numptr);
		if (!new_node)
			return (stack);
		ft_lstadd_front(&stack, new_node);
	}
	return (stack);
}
