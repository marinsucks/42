/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:14:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 20:26:29 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @return 1 if all args are digits separated by spaces, else 0
 */ 
int	is_correct_args(char **s)
{
	int	i;
	int	j;

	i = 0;
	//if (!s[1])
	//	return (0);
	while (s[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j++]))
				return (0);
		}
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == '-' || s[i][j] == '+')
				j++;
			if (!ft_isdigit(s[i][j++]) || ft_atoi(s[i]) != ft_atol(s[i]))
				return (0);
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
		if (!numptr)
			return (NULL);
		*numptr = ft_atoi(argv[--tablen]);
		new_node = ft_lstnew(numptr);
		if (!new_node)
			return (stack);
		ft_lstadd_front(&stack, new_node);
	}
	return (stack);
}

t_list	*ft_getcommands(char **args)
{
	t_list	*commands;
	t_list	*new_node;
	char 	*gnl;

	ft_printf("start\n");//delete me
	gnl = get_next_line(1); //infinite loop why ????
	while (gnl)
	{
		new_node = ft_lstnew(gnl);
		ft_lstadd_back(&commands, new_node);
		new_node->next = NULL;
		gnl = get_next_line(1);
	}
	commands = NULL;
	ft_printf("end\n");//delete me
	new_node = commands;
	while (new_node)//delete me
	{//delete me
		ft_printf("%s\n", new_node->content);//delete me
		new_node = new_node->next;//delete me
	}//delete me
	return (commands);
}

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*commands;
	char	**args;

	//if (argc <= 1)
	//	return (0);
	//else if (argc == 2)
	//	args = ft_split_charset(argv[1], SPACES);
	//else 
	//	args = (char **)argv + 1;
	//if (!is_correct_args(args))
	//	return (error(2));
	//stack_a = ft_getstack(ft_tablen((const char **)args), (const char **)args);
	//stack_b = NULL;
	//if (argc == 2)
	//	ft_freetab(args);

	commands = ft_getcommands(args);


	//ft_lstclear(&stack_a, free);
	//ft_lstclear(&stack_b, free);
}
