/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:12 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/16 16:26:37 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define TRUE 1 
# define FALSE 0

//main
t_list	*ft_getstack(int argc, const char *argv[]);

/************ COMMANDS ***********/
//ft_swap
void	ft_lstswap(t_list **node);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
//ft_push
void	ft_lstpush(t_list **src, t_list **dst);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa_sorted(t_list **stack_a, t_list **stack_b);
void	pb_sorted(t_list **stack_a, t_list **stack_b);
//ft_rotate
void	ft_rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
//ft_rrotate
void	ft_rrotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);


/************ SORTING ***********/
//ft_sort
int		ft_is_sorted(t_list *stack);
int		ft_find_unsorted(t_list *stack, int ascending);
//ft_insertionsort
void	ft_insertion_sort(t_list **stack_a, t_list **stack_b);





/************ TEST FUNCTIONS ***********/
void	printList(t_list *list);
void	printBoth(t_list **list_a, t_list **list_b);
void	swapTests(t_list *stack_a, t_list *stack_b);
void	pushTests(t_list *stack_a, t_list *stack_b);
void	rotateTests(t_list *stack_a, t_list *stack_b, char const *argv[]);
void	reverseRotateTests(t_list *stack_a, t_list *stack_b, char const *argv[]);

#endif
