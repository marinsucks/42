/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:10:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/15 17:28:19 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 1 if all args are digits, else 0 
int	is_correct_args(const char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//don't forget to free stack after use
t_list	*ft_getstack(int argc, char const *argv[])
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

int	main(int argc, char const *argv[]) 
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0);
	if (argc <= 2 || !is_correct_args(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = ft_getstack(argc, argv);
	stack_b = NULL;
	
	pb_sorted(&stack_a, &stack_b);	
	printBoth(&stack_a, &stack_b);
	pa_sorted(&stack_a, &stack_b);
	printBoth(&stack_a, &stack_b);

	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
