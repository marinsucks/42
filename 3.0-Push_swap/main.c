/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:10:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/10 16:31:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[]) // PENSER A REMETTRE COMMANDE LIBFT DS MAKEFILE
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0); // Return without displaying anything if no parameters are specified
	if (argc <= 2)
	{
		write(2, "Error\n", 6); // Display "Error" on standard error
		return (1);
	}
	stack_a = ft_getstack(argc, argv);
	//const char *b[] = {"./push_swap", "5", "6", "7", "8", "9", NULL};
	const char *b[] = {NULL};
	stack_b = ft_getstack(ft_tablen(b), b);
	printBoth(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
