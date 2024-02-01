/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:27:55 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/25 16:28:26 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/************ TEST FUNCTIONS ***********/
//main.c
t_list	*ft_getstack(int argc, const char *argv[]);
//test.print.c
void	printList(t_list **list);
int		printBoth(t_list **list_a, t_list **list_b);
//test.cmds.c
void	swapTests(t_list *stack_a, t_list *stack_b);
void	pushTests(t_list *stack_a, t_list *stack_b);
void	rotateTests(t_list *stack_a, t_list *stack_b, char const *argv[]);
void	reverseRotateTests(t_list *stack_a, t_list *stack_b, char const *argv[]);

