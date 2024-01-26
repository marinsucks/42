/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:57 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 18:49:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//SA/SB/SS
void	swapTests(t_list *stack_a, t_list *stack_b)
{
	const char *b[] = {"./push_swap", "5", "6", "7", "8", "9", NULL};
	stack_b = ft_getstack(ft_tablen(b), b);
	ft_printf("INITIAL STACKS:\n");
	printBoth(&stack_a, &stack_b);
	sa(&stack_a);
	printBoth(&stack_a, &stack_b);
	sb(&stack_b);
	printBoth(&stack_a, &stack_b);
	ss(&stack_a, &stack_b);
	printBoth(&stack_a, &stack_b);
}

void	pushTests(t_list *stack_a, t_list *stack_b)
{
	ft_printf("INITIAL STACKS:\n");
	printBoth(&stack_a, &stack_b);
	while (stack_a != NULL)
	{
		pa(&stack_a, &stack_b);
		printBoth(&stack_a, &stack_b);
	}
	while (stack_b != NULL)
	{
		pb(&stack_a, &stack_b);
		printBoth(&stack_a, &stack_b);
	}
}

void	rotateTests(t_list *stack_a, t_list *stack_b, char const *argv[])
{
	const char *b[] = {"./push_swap", "5", "6", "7", "8", "9", NULL};
	stack_b = ft_getstack(ft_tablen(b), b);

	ft_printf("INITIAL STACKS:\n");
	printBoth(&stack_a, &stack_b);

	ft_printf("\nRA:\n");
	for (size_t i = 1; i < ft_tablen(argv); i++)
	{
		ra(&stack_a);
		printBoth(&stack_a, &stack_b);
	}

	ft_printf("\nRB:\n");
	for (size_t i = 1; i < ft_tablen(b); i++)
	{
		rb(&stack_b);
		printBoth(&stack_a, &stack_b);
	}

	ft_printf("\nRR:\n");
	for (size_t i = 1; i < ft_tablen(argv) || i < ft_tablen(b); i++)
	{
		rr(&stack_a, &stack_b);
		printBoth(&stack_a, &stack_b);
	}
}

void	reverseRotateTests(t_list *stack_a, t_list *stack_b, char const *argv[])
{
	const char *b[] = {"./push_swap", "5", "6", "7", "8", "9", NULL};
	stack_b = ft_getstack(ft_tablen(b), b);

	ft_printf("INITIAL STACKS:\n");
	printBoth(&stack_a, &stack_b);

	ft_printf("\nRRA:\n");
	for (size_t i = 1; i < ft_tablen(argv); i++)
	{
		rra(&stack_a);
		printBoth(&stack_a, &stack_b);
	}

	ft_printf("\nRRB:\n");
	for (size_t i = 1; i < ft_tablen(b); i++)
	{
		rrb(&stack_b);
		printBoth(&stack_a, &stack_b);
	}

	ft_printf("\nRRR:\n");
	for (size_t i = 1; i < ft_tablen(argv) || i < ft_tablen(b); i++)
	{
		rrr(&stack_a, &stack_b);
		printBoth(&stack_a, &stack_b);
	}
}