/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:10:25 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/09 17:21:54 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

t_list	*ft_makestack(int argc, char const *argv[])
{
	t_list	*stack ;
	t_list	*new_node;
	int		*numptr;

	stack = NULL;
	while (argc > 1)
	{
		numptr = (int*)malloc(sizeof(int));
		*numptr = ft_atoi(argv[--argc]);
		new_node = ft_lstnew(numptr);
		if (!new_node)
			return (stack); //il faudra free la stack
		ft_lstadd_front(&stack, new_node); 
	}
	//free(numptr);

	return (stack);
}

int main(int argc, char const *argv[]) //PENSER A REMETTRE COMMANDE LIBFT DS MAKEFILE
{
	t_list	*stack ;
	t_list	*ptr;
	int		*numptr;

	if (argc <= 2)
	{
		ft_printf("\033[1;31mERROR:\033[0;31m not enough arguments.\n");
		return 0;
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

	return 0;
}

