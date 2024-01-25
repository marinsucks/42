/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:12 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/25 14:15:28 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define TRUE 1 
# define FALSE 0
# define SPACES " \t\n\v\f\r"

/************ COMMANDS ***********/
//ft_swap.c
void	ft_lstswap(t_list **node);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
//ft_push.c
void	ft_lstpush(t_list **src, t_list **dst);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa_sorted(t_list **stack_a, t_list **stack_b, int additional);
void	pb_sorted(t_list **stack_a, t_list **stack_b, int additional);
//ft_rotate.c
void	ft_lstrotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
//ft_rrotate.c
void	ft_lstrrotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);


/************ SORTING ***********/
//status.c
int		ft_is_sorted(t_list *stack);
t_list	*ft_getmin(t_list *stack);
//int		ft_find_unsorted(t_list *stack, int ascending);

//target.c
void	ft_settarget(t_list *to_set, t_list *src, int ascending);
void	ft_cleartarget(t_list *stack);

//cost.c
int		single_pushcost(t_list **list, t_list *node);
int		global_pushcost(t_list **srclist, t_list **tgetlist, t_list *node);
t_list	*ft_topush(t_list **srclist, t_list **tgetlist);

//optirotate.c
void	ft_optirotate_one(t_list **stack, t_list *node, char ab);
void	ft_optirotate(t_list **srclist, t_list **tgtlst, t_list *node, char ab);

//algos.c
void	ft_threesort(t_list **stack_a);
void	ft_turksort(t_list **stack_a, t_list **stack_b);





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

#endif
