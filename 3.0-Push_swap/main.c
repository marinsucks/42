/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:10:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/11 19:29:59 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char const *argv[]) // PENSER A REMETTRE COMMANDE LIBFT DS MAKEFILE
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc <= 1)
		return (0); // Return without displaying anything if no parameters are specified
	if (argc <= 2 || !is_correct_args(argv))
	{
		write(2, "Error\n", 6); // Display "Error" on standard error
		return (1);
	}
	stack_a = ft_getstack(argc, argv);
	stack_b = NULL;
	
	/*************TESTS*************/
	//swapTests(stack_a, stack_b, argv);
	//pushTests(stack_a, stack_b, argv);
	//rotateTests(stack_a, stack_b, argv);
	reverseRotateTests(stack_a, stack_b, argv);


	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
