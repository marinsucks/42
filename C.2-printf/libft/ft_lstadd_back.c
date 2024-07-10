/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:26:08 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/17 12:07:48 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (new)
	{
		if (!last)
		{
			*lst = new;
			return ;
		}
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

/*IMPLEMENTATION POSSIBLE SI NEW = NULL

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if(new)
	{
		if (!last)
		{
			*lst = new;
			return ;
		}
		while (last->next)
			last = last->next;

		last->next = new;
	}
}*/