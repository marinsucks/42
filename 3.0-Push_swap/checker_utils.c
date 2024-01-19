/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:05 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/19 14:30:28 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

//gets commands from stdin and returns a list of commands
t_list	*ft_getcmds(char **args)
{
	t_list	*commands;
	t_list	*new_node;
	char	*gnl;

	gnl = get_next_line(0);
	commands = NULL;
	while (gnl)
	{
		new_node = ft_lstnew((char *)gnl);
		ft_lstadd_back(&commands, new_node);
		new_node->next = NULL;
		gnl = get_next_line(0);
	}
	return (commands);
}

//executes a command from the current node, or returns error if invalid command
void	ft_makecmd(t_list **stack_a, t_list **stack_b, t_list *command)
{
	if (!ft_strcmp((char *)command->content, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp((char *)command->content, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp((char *)command->content, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp((char *)command->content, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp((char *)command->content, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp((char *)command->content, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp((char *)command->content, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp((char *)command->content, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp((char *)command->content, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp((char *)command->content, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp((char *)command->content, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		exit(error(2));
}

//executes and check the program
int	ft_execheck(t_list **stack_a, t_list **stack_b, t_list *command)
{
	while (command)
	{
		ft_makecmd(stack_a, stack_b, command);
		command = command->next;
	}
	if (ft_is_sorted(*stack_a) && !*stack_b)
		return (1);
	return (0);
}
