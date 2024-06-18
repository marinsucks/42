/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:28:22 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/18 17:44:42 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state(t_philo *philo, char *status)
{
	printf(
		"\033[0;36m%d\033[0;90m\t%d\033[0m %s\n",
		gettimestamp(philo->data->start_time),
		philo->id + 1,
		status);
}

/**
 * @brief Function to handle the death of a philosopher. 
 * 
 * It prints `"X X died"`, detaches its associated thread
 * and returns 1.
 * 
 * @param philo A pointer to the philosopher structure.
 * @return int Returns 1.
 */
int dies(t_philo *philo)
{
	state(philo, "died");
	pthread_detach(philo->thread);
	philo->died = 1;
	return (1);
}

int	eats(t_philo *philo)
{
	philo->last_meal = gettimestamp(philo->data->start_time);
	state(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_mutex);	//cense autoriser l'acces
	pthread_mutex_unlock(philo->right_mutex);	//cense autoriser l'acces
	return (0);
}


void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->simulation_start)
		;
	philo->data->start_time = gettimestamp(0);
	while (philo->max_meal--)
	{
		if (takes_forks(philo))
			return (NULL);
		eats(philo);
	}
	return (0);
}
