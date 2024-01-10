/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:54:27 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/10 16:27:50 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printList(t_list *list)
{
	int *value;
	while (list)
	{
		value = list->content;
		ft_printf("%d\n", *value);
		list = list->next;
	}
}

void	printBoth(t_list *list_a, t_list *list_b)
{
	int *value_a;
	int *value_b;
	int len_a = ft_lstsize(list_a);
	int len_b = ft_lstsize(list_b);

	while (len_a > len_b)
	{
		value_a = list_a->content;
		ft_printf("%d\t\n", *value_a);
		list_a = list_a->next;
		len_a--;
	}
	while (len_b > len_a)
	{
		value_b = list_b->content;
		ft_printf("\t%d\n", *value_b);
		list_b = list_b->next;
		len_b--;
	}
	while (list_a || list_b)
	{
		value_a = list_a->content;
		value_b = list_b->content;
		ft_printf("%d\t%d\n", *value_a, *value_b);
		list_a = list_a->next;
		list_b = list_b->next;
	}
	ft_printf("\033[1;37m_\t_\nA\tB\n\033[0m");
	//ft_printf("%d\t%d\n", len_a, len_b);
}
