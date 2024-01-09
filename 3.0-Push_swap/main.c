/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:10:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/09 23:54:27 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[]) // PENSER A REMETTRE COMMANDE LIBFT DS MAKEFILE
{
	t_list	*stack;
	t_list	*ptr;
	int		*numptr;

	write(1, "\033[1;31mtest\n", 13);
	if (argc <= 2)
	{
		ft_printf("\033[1;31mERROR:\033[0;31m not enough arguments.\n");
		return (0);
	}
	stack = ft_makestack(argc, argv);
	ptr = stack;
	while (ptr)
	{
		numptr = ptr->content;
		ft_printf("%d", *numptr);
		ptr = ptr->next;
	}
	ft_lstclear(&stack, free);
	return (0);
}
