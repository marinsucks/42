/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:02:33 by mbecker           #+#    #+#             */
/*   Updated: 2024/02/19 13:23:41 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

/**
 * @brief Frees a char **tab and its content.
 * @param tab The tab to free.
 * @param heap If 1, frees the tab itself.
 */
void	freetab(char **tab, int heap)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (heap)
		free(tab);
}
