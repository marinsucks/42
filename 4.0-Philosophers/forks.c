/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:04:36 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/18 17:45:04 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	if (gettimestamp(philo->data->start_time) - philo->last_meal
		> philo->data->time_to_die)
		return (dies(philo));
	return (0);
}

int	grab_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_mutex);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->left_mutex);
		return (1);
	}
	if (!*philo->left_fork) //DEBUG
		printf("philo %d: left fork already taken, but mutex inefficient\n", philo->id); // DEBUG
	//*philo->left_fork = 0;
	state(philo, "has taken a fork");
	return (0);
}

int	grab_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_mutex);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->right_mutex);
		return (1);
	}
	if (!*philo->right_fork) //DEBUG
		printf("philo %d: right fork already taken, but mutex inefficient\n", philo->id); // DEBUG
	//*philo->right_fork = 0;
	state(philo, "has taken a fork");
	return (0);
}

int	takes_forks(t_philo *philo)
{

	if (!philo->data->time_to_die || philo->left_fork == philo->right_fork)
		return (dies(philo));

	if (philo->id % 2 == 0)
	{
		if (grab_left_fork(philo))
			return (1);
		if (grab_right_fork(philo))
			return (1);
	}
	else
	{
		if (grab_right_fork(philo))
			return (1);
		if (grab_left_fork(philo))
			return (1);
	}

	return (0);
}
