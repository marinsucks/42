/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:07:48 by mbecker           #+#    #+#             */
/*   Updated: 2023/11/16 19:24:20 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if(!lst)
		return (0);
	ptr = lst->next;
	while (ptr)
	{
		if (!ptr->next)
			ptr = ptr->next;
	}
	return (ptr);
}
