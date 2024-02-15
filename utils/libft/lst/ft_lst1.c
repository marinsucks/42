/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:28:31 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

//allocates (with malloc(3)) and returns a new element.
t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

//adds the node ’new’ at the beginning of the list 'lst'.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

//adds the node ’new’ at the end of the list.
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

//applies func del to the content of the node and frees the node.
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	if (!lst)
		return (0);
	i = 1;
	ptr = lst->next;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
