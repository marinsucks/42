/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:14:48 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/19 14:41:15 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*commands;
	char	**args;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
		args = ft_split_charset(argv[1], SPACES);
	else 
		args = (char **)argv + 1;
	if (!is_correct_args(args))
		return (error(2));
	stack_a = ft_getstack(ft_tablen((const char **)args), (const char **)args);
	stack_b = NULL;
	if (argc == 2)
		ft_freetab(args);
	commands = ft_getcmds(args);
	if (ft_execheck(&stack_a, &stack_b, commands))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	ft_lstclear(&commands, free);
}
