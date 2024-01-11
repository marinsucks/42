/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:12 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/11 18:55:25 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//ft_stack
t_list	*ft_getstack(int argc, char const *argv[]);

//ft_swap
void    ft_lstswap(t_list **node);
void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);

//ft_push
void	ft_lstpush(t_list **src, t_list **dst);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

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

//test functions
void	printList(t_list *list);
void	printBoth(t_list **list_a, t_list **list_b);
void	swapTests(t_list *stack_a, t_list *stack_b);
void	pushTests(t_list *stack_a, t_list *stack_b);
void	rotateTests(t_list *stack_a, t_list *stack_b, char const *argv[]);
void	reverseRotateTests(t_list *stack_a, t_list *stack_b, char const *argv[]);

#endif
