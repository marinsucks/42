/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:09:40 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/14 15:31:17 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Frees n pointers of an array.
 * @param tab The tab to free.
 * @param heap If 1, frees the tab itself.
 */
void	freentab(char **tab, int heap, int n)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i < n && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (heap)
		free(tab);
}

void	freedata(t_data *data)
{
	freentab((char **)data->forum, TRUE, data->nb_philo);
	freentab((char **)data->forks, TRUE, data->nb_philo);
}
