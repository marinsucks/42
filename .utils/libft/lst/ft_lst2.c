/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:28:31 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/15 17:14:44 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

// applies func del to the content of each node and frees each node.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		next = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = next;
	}
	*lst = NULL;
}

// iterates the list lst and applies the function f to the content of each node.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;
	t_list	*next;

	ptr = lst;
	if (!lst || !f)
		return ;
	while (ptr)
	{
		next = ptr->next;
		f(ptr->content);
		ptr = next;
	}
}

// returns the last element of the list.
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

// @returns index of tofind in lst, starting at 0.
int	ft_lstindex(t_list **lst, t_list *tofind)
{
	int		i;
	t_list	*ptr;

	if (!lst)
		return (0);
	i = 0;
	ptr = *lst;
	while (ptr != tofind)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/**Iterates the list lst and applies the func f to the content of each element.
 * Creates and returns a new list resulting of the successive applications of f.
 * The ’del’ function is used to delete the content of an element if needed.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	new_node = NULL;
	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
