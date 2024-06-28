/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:28:22 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/28 16:12:39 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state(t_philo *philo, char *status)
{
	pthread_mutex_lock(&(philo->data->printf_mutex));
	if (!philo->data->death && !philo->data->all_full)
	{
		printf("\033[0;36m%d\t", gettimestamp(philo->data->start_time));
		printf("\033[0;90m%d ", philo->id + 1);
		printf("\033[0m %s\n", status);
	}
	pthread_mutex_unlock(&(philo->data->printf_mutex));
}

void	ft_usleep(int time, t_data *data)
{
	int		start;
	int		current;

	start = gettimestamp(data->start_time);
	while (!data->death)
	{
		current = gettimestamp(data->start_time);
		if (current - start >= time)
			return ;
		usleep(50);
	}
}

int	eats(t_philo *philo)
{
	pthread_mutex_lock(philo->left_mutex);
	state(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_mutex);
	state(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->data->check_mutex));
	philo->last_meal = gettimestamp(philo->data->start_time);
	state(philo, "is eating");
	pthread_mutex_unlock(&(philo->data->check_mutex));
	ft_usleep(philo->data->time_to_eat, philo->data);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_unlock(philo->right_mutex);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (!data->simulation_start)
		;
	philo->last_meal = data->start_time;
	if (!data->time_to_die || data->nb_philo == 1)
		return (dies(philo), NULL);
	if (philo->id % 2)
		usleep(15000);
	while (!data->death)
	{
		eats(philo);
		if (data->all_full)
			break ;
		state(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		state(philo, "is thinking");
	}
	return (NULL);
}
