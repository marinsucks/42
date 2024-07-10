/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:57:29 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/28 16:13:18 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	return (gettimestamp(philo->data->start_time)
		- philo->last_meal > philo->data->time_to_die);
}

/**
 * @brief Function to handle the death of a philosopher. 
 * 
 * It prints `"X X died"`, detaches its associated thread
 * and returns 1.
 * 
 * @return 1.
 */
int	dies(t_philo *philo)
{
	state(philo, "died");
	philo->died = 1;
	philo->data->death++;
	pthread_detach(philo->thread);
	return (1);
}

void	check_deaths(t_data *d)
{
	t_philo	*philo;
	int		i;

	while (!d->all_full)
	{
		i = -1;
		while (++i < d->nb_philo && !(d->death))
		{
			philo = d->philo_tab[i];
			pthread_mutex_lock(&(d->check_mutex));
			if (is_dead(philo))
				dies(philo);
			pthread_mutex_unlock(&(d->check_mutex));
			usleep(100);
		}
		if (d->death)
			return ;
		i = 0;
		while (d->max_meal != -1 && i < d->nb_philo
			&& d->philo_tab[i]->meals_eaten >= d->max_meal)
			i++;
		if (i == d->nb_philo)
			d->all_full = TRUE;
	}
}

/**
 * Creates threads for each philosopher and initializes their data.
 *
 * @return 0 if successful, -1 if an error occurred.
 */
int	create_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	pthread_mutex_init(&data->printf_mutex, NULL);
	pthread_mutex_init(&data->check_mutex, NULL);
	while (i < data->nb_philo)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (error("fatal: malloc failed\n"));
		*philo = (t_philo){philo->thread, i, &(data->forks[i]),
			&(data->forks[(i + 1) % data->nb_philo]), 0, 0, 0, data};
		data->philo_tab[i] = philo;
		pthread_mutex_init(&(data->forks[i]), NULL);
		if (pthread_create(&philo->thread, NULL, &philo_routine, philo))
			return (error("pthread_create failed\n"), i);
		i++;
	}
	data->start_time = gettimestamp(0);
	data->simulation_start = 1;
	check_deaths(data);
	return (0);
}

/**
 * Joins all the threads created for the philosophers and destroys the mutexes.
 */
void	join_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo = data->philo_tab[i];
		if (!philo->died && pthread_join(philo->thread, NULL))
			error("pthread_join failed\n");
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&data->printf_mutex);
	pthread_mutex_destroy(&data->check_mutex);
}
