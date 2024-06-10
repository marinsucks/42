/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:09:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/10 18:10:37 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	freedata(t_data data)
{
	free(data.params);
	freetab((char **)data.forum, TRUE);
}
