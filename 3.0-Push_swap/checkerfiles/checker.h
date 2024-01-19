/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:46:46 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/19 14:45:02 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

//checker.c
int		is_correct_args(char **s);
t_list	*ft_getstack(int tablen, const char *argv[]);

//checker_utils.c
t_list	*ft_getcmds(char **args);
void	ft_makecmd(t_list **stack_a, t_list **stack_b, t_list *command);
int		ft_execheck(t_list **stack_a, t_list **stack_b, t_list *command);

#endif