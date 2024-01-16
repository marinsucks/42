/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:10:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/16 17:23:38 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 1 if all args are digits, else 0 
int	is_correct_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	if (!args[1])
		return (0);
	while (args[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j++]))
				return (0);
		}
		while (args[i][j])
		{
			if (args[i][j] == '-')
				j++;
			if (!ft_isdigit(args[i][j]) || ft_atoi(args[i]) != ft_atol(args[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//allocates and returns a stack with all args
t_list	*ft_getstack(int tablen, const char *argv[])
{
	t_list	*stack;
	t_list	*new_node;
	int		*numptr;

	stack = NULL;
	while (tablen >= 1)
	{
		numptr = (int *)malloc(sizeof(int));
		*numptr = ft_atoi(argv[--tablen]);
		new_node = ft_lstnew(numptr);
		if (!new_node)
			return (stack);
		ft_lstadd_front(&stack, new_node);
	}
	ft_freetab((char **)argv);
	return (stack);
}

#include <stdio.h>

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	if (argc <= 1)
		return (0);
	args = 	ft_split(argv[1], ' ');
	if (!is_correct_args(args)) // doesn't work when x is at the end of str
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = ft_getstack(ft_tablen((const char **)args), (const char **)args);
	stack_b = NULL;

	//ft_insertion_sort(&stack_a, &stack_b);

	
	//ft_printf("\n\033[1;31mFINAL RESULTS\033[0m\n");
	printBoth(&stack_a, &stack_b); //delete me
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
