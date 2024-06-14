/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:28:22 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/14 17:41:42 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state(t_philo *philo, char *status)
{
	int	start;

	start = philo->data->start_time;
	printf("\033[0;36m%d\033[0;90m\t%d\033[0m %s\n", gettimestamp(start), philo->id, status);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!*philo->left_fork || !*philo->right_fork)
		;
	*philo->left_fork = 0;
	state(philo, "has taken a fork");
	*philo->right_fork = 0;
	state(philo, "has taken a fork");
	state(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	*philo->left_fork = 1;
	*philo->right_fork = 1;
	return (0);
}
