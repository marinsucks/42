/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:54:27 by mbecker           #+#    #+#             */
/*   Updated: 2024/01/18 18:49:53 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	printList(t_list **list)
{
	t_list *ptr = *list;
	while (ptr)
	{
		ft_printf("%d\n", *ptr->content);
		ptr = ptr->next;
	}
	ft_printf("\033[1;34m_\nx\n\033[0m");
	ft_printf("\033[0;34m%d\n\n\033[0m", ft_lstsize(*list));
}

void	printBoth(t_list **list_a, t_list **list_b)
{
	int len_a = ft_lstsize(*list_a);
	int len_b = ft_lstsize(*list_b);
	t_list *ptr_a = *list_a;
	t_list *ptr_b = *list_b;
	
	while (len_a > len_b)
	{
		ft_printf("%d\n", *(int *)ptr_a->content);
		ptr_a = ptr_a->next;
		len_a--;
	}
	while (len_b > len_a)
	{
		ft_printf("\t%d\n", *(int *)ptr_b->content);
		ptr_b = ptr_b->next;
		len_b--;
	}
	while (ptr_a != NULL || ptr_b != NULL)
	{
		ft_printf("%d", *(int *)ptr_a->content);
		ft_printf("\t%d\n", *(int *)ptr_b->content);
		ptr_a = ptr_a->next;
		ptr_b = ptr_b->next;
	}
	ft_printf("\033[1;32m_\t_\nA\tB\n\033[0m");
	ft_printf("\033[0;32m%d\t%d\n\n\033[0m", ft_lstsize(*list_a), ft_lstsize(*list_b));
}

//void	printBothLong(t_list **list_a, t_list **list_b)
//{
//	int *value_a;
//	int *value_b;
//	int len_a = ft_lstsize(*list_a);
//	int len_b = ft_lstsize(*list_b);
//	t_list *ptr_a = *list_a;
//	t_list *ptr_b = *list_b;

//	while (len_a > len_b)
//	{
//		value_a = ptr_a->content;
//		ft_printf("%d\n", *value_a);
//		ptr_a = ptr_a->next;
//		len_a--;
//	}
//	while (len_b > len_a)
//	{
//		value_b = ptr_b->content;
//		ft_printf("\t\t%d\n", *value_b);
//		ptr_b = ptr_b->next;
//		len_b--;
//	}
//	while (ptr_a != NULL || ptr_b != NULL)
//	{
//		value_a = ptr_a->content;
//		value_b = ptr_b->content;
//		if (*value_a <= 99999999)
//			ft_printf("%d\t\t%d\n", *value_a, *value_b);
//		else
//			ft_printf("%d\t%d\n", *value_a, *value_b);
//		ptr_a = ptr_a->next;
//		ptr_b = ptr_b->next;
//	}
//	ft_printf("\033[1;32m_\t\t_\nA\t\tB\n\033[0m");
//	ft_printf("\033[0;32m%d\t\t%d\n\n\033[0m", ft_lstsize(*list_a), ft_lstsize(*list_b));
//}
