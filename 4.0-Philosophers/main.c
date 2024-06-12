/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:24:42 by mbecker           #+#    #+#             */
/*   Updated: 2024/06/12 17:43:43 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Calculates the timestamp in milliseconds since the start of the program.
 *
 * @param params The original start time of the program in milliseconds, or 0 
 * to set it.
 * @return The timestamp in milliseconds.
 */
int	gettimestamp(int start_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - start_time);
}

int	create_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < data->params->nb_philo)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (error("malloc failed\n"));
		*philo = (t_philo){0, i, 0, 0, 0, data};
		data->forum[i++] = philo;
		if (pthread_create(&philo->thread, NULL, &philo_routine, philo))
			return (error("pthread_create failed\n"));
	}
	data->forum[i] = NULL;
	return (0);
}

int	main(int ac, char const *av[])
{
	t_data	data;
	int		i;

	data.params = philo_parsing(ac, av);
	if (!data.params)
		return (1);
	data.params->start_time = gettimestamp(data.params->start_time);
	data.forum = malloc((sizeof(t_philo *) * data.params->nb_philo) + 8);
	if (!data.forum)
		return (error("malloc failed\n"));
	pthread_mutex_init(&data.mutex, NULL);
	if (create_threads(&data))
		return (error("create_threads failed\n"));
	i = 0;
	while (i < data.params->nb_philo)
	{
		if (pthread_join(data.forum[i++]->thread, NULL))
			return (error("pthread_join failed\n"));
	}
	pthread_mutex_destroy(&data.mutex);
	freedata(data);
	return (0);
}

//void	*print_structs(t_data data)
//{
//	printf("start_time: \t%d\n", data.params->start_time);
//	printf("nb_philo: \t%d\n", data.params->nb_philo);
//	printf("time_to_die: \t%d\n", data.params->time_to_die);
//	printf("time_to_eat: \t%d\n", data.params->time_to_eat);
//	printf("time_to_sleep: \t%d\n", data.params->time_to_sleep);
//	printf("nb_must_eat: \t%d\n", data.params->nb_must_eat);
//	printf("forks: \t\t%d\n", data.params->forks);
//	printf("forks_status: \t%p\n", (void*)data.params->forks_status);
//	printf("last_meal: \t%p\n", (void*)data.params->last_meal);
//	printf("nb_meal: \t%p\n", (void*)data.params->nb_meal);
//	printf("is_dead: \t%p\n", (void*)data.params->is_dead);
//	printf("is_full: \t%p\n", (void*)data.params->is_full);
//	printf("mutex: \t\t%p\n", (void*)data.params->mutex);
//	printf("print_mutex: \t%p\n", (void*)data.params->print_mutex);
//	printf("dead_mutex: \t%p\n", (void*)data.params->dead_mutex);
//	printf("full_mutex: \t%p\n", (void*)data.params->full_mutex);
//}
