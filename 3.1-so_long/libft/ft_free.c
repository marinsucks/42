/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:02:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/05 15:07:56 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees a char **tab and its content.
 * @param tab The tab to free.
 * @param heap If 1, frees the tab itself.
 */
void	ft_freetab(char **tab, int heap)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (heap)
		free(tab);
}

/**
 * @brief Frees all pointers passed as arguments. Handles 3 modes:
 *
 * @param mode
 * @param 1: void   *ptr
 * @param 2: void   **ptr
 * @param 3: t_list **ptr
 * @note add a NULL pointer at the end of the arguments.
 */
int	ft_free(int mode, ...)
{
	va_list	args;
	void	*ptr;

	va_start(args, mode);
	ptr = va_arg(args, void *);
	while (ptr && mode <= 3 && mode >= 1)
	{
		if (mode == 1)
			free(ptr);
		else if (mode == 2)
			ft_freetab((char **)ptr, TRUE);
		else if (mode == 3)
			ft_lstclear((t_list **)ptr, free);
		else
			ft_printf("Error: ft_free: wrong mode\n");
		ptr = va_arg(args, void *);
	}
	va_end(args);
	return (1);
}
